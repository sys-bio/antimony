#include "layoutWrapper.h"
#include "module.h"
#include "registry.h"
#include "stringx.h"
#include "regex"
#include "reaction.h"
#include <iostream>
#include <string>
#include <regex>
#ifdef LIBSBML_HAS_PACKAGE_DISTRIB
#include <sbml/packages/layout/sbml/Layout.h>
#include <sbml/packages/layout/extension/LayoutModelPlugin.h>
#endif
#include <sbmlnetwork/libsbmlnetwork_sbmldocument.h>
#include <sbmlnetwork/libsbmlnetwork_sbmldocument_layout.h>
#include <sbmlnetwork/libsbmlnetwork_sbmldocument_render.h>
#include <sbmlnetwork/libsbmlnetwork_render_helpers.h>
#include <sbmlnetwork/libsbmlnetwork_layout.h>

using namespace std;
using namespace libsbml;

LayoutWrapper::LayoutWrapper(Variable* parent, layout_type type, string name, const Module* module)
    : Variable(name, module)
    , m_parent(parent)
    , m_layout_type(type)
    , m_speciesId("")
    , m_speciesIndex(-1)
    , m_segmentIndex(-1)
    , m_arctype(at_none)
    , m_aliasNum(0)
    , m_aliasReactionConnections()
{
    m_module = parent->GetNamespace();
    m_displayname = "";
    m_formulatype = formulaINITIAL;
    m_supercomptype = varUndefined;
    m_deletedunit = false;
    m_replacedformrxn = false;
    m_const = constDEFAULT;
    m_substOnly = false;
    m_sboTermWrapper = NULL;
    m_type = varLayoutWrapper;
    SetNamespace(parent->GetNamespace());
}

LayoutWrapper::LayoutWrapper(Variable* parent, layout_type type)
    : Variable()
    , m_parent(parent)
    , m_layout_type(type)
    , m_speciesId("")
    , m_speciesIndex(-1)
    , m_segmentIndex(-1)
    , m_arctype(at_none)
    , m_aliasNum(0)
    , m_aliasReactionConnections()
{
    m_module = parent->GetNamespace();
    m_displayname = "";
    m_formulatype = formulaINITIAL;
    m_supercomptype = varUndefined;
    m_deletedunit = false;
    m_replacedformrxn = false;
    m_const = constDEFAULT;
    m_substOnly = false;
    m_sboTermWrapper = NULL;
    m_type = varLayoutWrapper;
    SetNamespace(parent->GetNamespace());
}

LayoutWrapper::LayoutWrapper(layout_type type, const string& group)
    : Variable()
    , m_parent(NULL)
    , m_layout_type(type)
    , m_speciesId("")
    , m_speciesIndex(-1)
    , m_segmentIndex(-1)
    , m_arctype(at_none)
{
    m_displayname = "";
    m_formulatype = formulaINITIAL;
    m_supercomptype = varUndefined;
    m_deletedunit = false;
    m_replacedformrxn = false;
    m_const = constDEFAULT;
    m_substOnly = false;
    m_sboTermWrapper = NULL;
    m_name.push_back(group);
    m_name.push_back(LayoutTypeToString(type));
    m_type = varLayoutWrapper;
}

LayoutWrapper::~LayoutWrapper()
{
}

bool LayoutWrapper::IsPointer() const
{
    return false;
}

//Variable* LayoutWrapper::GetSameVariable()
//{
//    return m_parent;
//}
//
//const Variable* LayoutWrapper::GetSameVariable() const
//{
//    return m_parent;
//}
//
bool LayoutWrapper::SetFormula(Formula* formula, bool isObjective)
{
    if (Variable::SetFormula(formula, isObjective)) {
        string formstring = formula->ToSBMLString();
        ColorDefinition cd;
        if (!cd.setColorValue(formstring)) {
            formstring = "#" + formstring;
            if (!cd.setColorValue(formstring)) {
                return true;
            }
            formula->Clear();
            formula->AddText(&formstring, true);
        }
        //If it's a valid color definition, we can use it
        m_valFormula = *formula;
    }

    if (formula->IsEmpty()) {
        assert(false);
    }

    if (IsPair(m_layout_type)) {
        //Only Vectors of length 2 are allowed for these types
        ASTNode* astn = parseStringToASTNode(formula->ToSBMLString());
        if (!astn || astn->getType() != AST_LINEAR_ALGEBRA_VECTOR || astn->getNumChildren() != 2) {
            g_registry.SetError("Unable to set the value of '" + GetNameDelimitedBy(".") + "' to be '" + formula->ToDelimitedStringWithEllipses(".") + "':  a layout parameter of type " + LayoutTypeToString(m_layout_type) + " must be a vector of length two, marked with curly brackets (i.e. '{150, 200}').");
            delete astn;
            return true;
        }
        for (unsigned int c = 0; c < 2; c++) {
            ASTNodeType_t ctype = astn->getChild(c)->getType();
            if (!astn->getChild(c)->isNumber()) {
                g_registry.SetError("Unable to set the value of '" + GetNameDelimitedBy(".") + "' to be '" + formula->ToDelimitedStringWithEllipses(".") + "':  a layout parameter of type " + LayoutTypeToString(m_layout_type) + " must be a vector of length two, and each element of the vector may only be a value (i.e. '{150, 200}').");
                delete astn;
                return true;
            }
        }
        if (astn->getChild(0)->isSetUnits() || astn->getChild(1)->isSetUnits()) {
            g_registry.SetError("Unable to set the value of '" + GetNameDelimitedBy(".") + "' to be '" + formula->ToDelimitedStringWithEllipses(".") + "':  units may not be used for layout positions.");
            delete astn;
            return true;
        }
        if (m_layout_type == lt_size && (astn->getChild(0)->getValue() < 0 || astn->getChild(1)->getValue() < 0)) {
            g_registry.SetError("Unable to set the value of '" + GetNameDelimitedBy(".") + "' to be '" + formula->ToDelimitedStringWithEllipses(".") + "':  size may not be negative.");
            delete astn;
            return true;
        }
        delete astn;
        return false;
    }
    else {
        string formstring = m_valFormula.ToSBMLString();
        ASTNode* astn_ptr = parseStringToASTNode(formstring);
        ASTNode astn;
        if (astn_ptr) {
            astn = *astn_ptr;
        }
        delete astn_ptr;
        double lval = astn.getValue();
        string strval = "";
        if (astn.getType() == AST_NAME) {
            strval = astn.getName();
        }
        if (formula->IsOneComponent()) {
            vector<Variable*> varvec = formula->GetVariables();
            if (varvec.size() > 0) {
                if (varvec[0]->SetType(varLayoutColorEtc)) {
                    return true;
                }
            }
            switch (m_layout_type) {
            case lt_x:
            case lt_y:
            case lt_height:
            case lt_width:
            case lt_fontsize:
            case lt_linewidth:
                if (!astn.isNumber()) {
                    g_registry.SetError("Unable to set the value of '" + GetNameDelimitedBy(".") + "' to '" + formula->ToDelimitedStringWithEllipses(".") + "'.  It may only be set to a numerical value.");
                    return true;
                }
                break;
            case lt_color:
            case lt_fontcolor:
            case lt_linecolor:
                if (!isValidColorValue(formstring)) {
                    g_registry.SetError("Unable to set the value of '" + GetNameDelimitedBy(".") + "'.  '" + formula->ToDelimitedStringWithEllipses(".") + "' is not a valid color value.  Try standard color names like 'red' or 'blue', or use an RGB value of the form \"#000000\" (including the quotation marks).");
                    return true;
                }
                return false;
            case lt_font:
                if (!LIBSBMLNETWORK_CPP_NAMESPACE::isValidFontFamilyValue(formstring)) {
                    g_registry.SetError("Unable to set the value of '" + GetNameDelimitedBy(".") + "'.  '" + formula->ToDelimitedStringWithEllipses(".") + "' is not a valid font value.  The predefined fonts are the general 'serif', 'sans_serif' and 'monospace', but arbitrary font names are also legal.");
                    return true;
                }
                return false;
            case lt_fontstyle:
            case lt_fontweight:
                if (!isValidFontStyle(formstring)) {
                    g_registry.SetError("Unable to set the value of '" + GetNameDelimitedBy(".") + "'.  '" + formula->ToDelimitedStringWithEllipses(".") + "' is not a valid font style.  The valid font styles and weights are 'normal', 'bold', 'italic', and 'bold_italic'.");
                    return true;
                }
                return false;
            case lt_shape:
                if (!LIBSBMLNETWORK_CPP_NAMESPACE::isValidGeometricShapeName(formstring)) {
                    g_registry.SetError("Unable to set the value of '" + GetNameDelimitedBy(".") + "'.  '" + formula->ToDelimitedStringWithEllipses(".") + "' is not a valid shape name.  The valid shape names are 'rectangle', 'square', 'ellipse', 'circle', 'triangle', 'diamond', 'pentagon', 'hexagon', and 'octagon'.");
                    return true;
                }
                return false;
            case lt_position:
            case lt_size:
            case lt_reactionArc:
                assert(false); //Should be pairs
                break;
            case lt_sourceSink:
                assert(false); //Should be base variable, not child.
                break;
            case lt_unknown:
                break;
            }
            return false;
        }
        g_registry.SetError("Unable to set the value of '" + GetNameDelimitedBy(".") + "' to be '" + formula->ToDelimitedStringWithEllipses(".") + "':  this layout parameter must only be a single value or a single variable.");
        return true;
    }
    return false;
}

bool LayoutWrapper::SetType(var_type newtype)
{
    if (newtype == m_type) {
        return false;
    }
    g_registry.SetError("Unable to use the symbol '" + GetNameDelimitedBy(".") + "' in any context other than setting its value.");
    return true;
}

//bool LayoutWrapper::SetlayoutType(layout_type newtype)
//{
//  m_layout_type = newtype;
//}

layout_type LayoutWrapper::GetLayoutType()
{
    return m_layout_type;
}

int LayoutWrapper::GetAliasNum()
{
    return m_aliasNum;
}

Variable* LayoutWrapper::GetParent()
{
    return m_parent;
}

string LayoutWrapper::GetNameDelimitedBy(string cc) const
{
    if (m_layout_type == lt_sourceSink && cc == "_") {
        return m_speciesId;
    }
    stringstream ret;
    if (m_parent) {
        if (m_layout_type == lt_reactionArc) {
            ret << m_parent->GetNameDelimitedBy(cc) << cc;
            if (m_speciesId.empty()) {
                ret << LayoutTypeToString(lt_sourceSink);
            }
            else {
                ret << m_speciesId;
            }
            if (m_speciesIndex > 0) {
                ret << cc << "arc" << m_speciesIndex + 1;
            }
            if (m_segmentIndex > 0) {
                ret << cc << "seg" << m_segmentIndex + 1;
            }
            ret << cc << ArcTypeToString(m_arctype);
        }
        else {
            ret << m_parent->GetNameDelimitedBy(cc) << cc << LayoutTypeToString(m_layout_type);
        }
        if (m_aliasNum > 0 && m_aliasReactionConnections.size() == 0) {
            ret << m_aliasNum+1;
        }
        for (size_t rxn = 0; rxn < m_aliasReactionConnections.size(); rxn++) {
            ret << "." << m_aliasReactionConnections[rxn];
        }
        return ret.str();
    }
    else {
        return Variable::GetNameDelimitedBy(cc);
    }
}

bool LayoutWrapper::Synchronize(Variable* clone, const Variable* conversionFactor)
{
    g_registry.SetError("Unable to synchronize two symbols when one of them ('" + GetNameDelimitedBy(".") + "') is a layout term.");
    return true;
}

string LayoutWrapper::CreateLayoutParamsAntimonySyntax(const string& indent) const
{
    string ret = "";
    if (!m_valFormula.IsEmpty()) {
        string strval = m_valFormula.ToDelimitedStringWithEllipses(".");
        if (strval[0] == '#' || (strval[0] != '{' && ((strval.find('-') != string::npos) || (strval.find(' ') != string::npos)))) {
            strval = '"' + strval + '"';
        }
        ret = indent + GetNameDelimitedBy(".") + " = " + strval + "\n";
    }
    if (!m_displayname.empty()) {
        ret += indent + GetNameDelimitedBy(".") + " is " + quoteText(m_displayname) + "\n";
    }
    for (size_t lw = 0; lw < m_layoutWrappers.size(); lw++) {
        ret += m_layoutWrappers[lw]->CreateLayoutParamsAntimonySyntax(indent);
    }
    return ret;
}

bool LayoutWrapper::TransferLayoutInformationTo(SBMLDocument* sbml)
{
    //g_registry.SetError("The variable " + sid + " is a species, so its alias nodes are set by listing the reactions for which it is an alias (i.e. 'S1.position.J2.J3' for an alias of S1 that is used in reactions J2 and J3).");
    string sid = m_parent->GetNameDelimitedBy("_");
    if (m_aliasReactionConnections.size()) {
        if (m_aliasNum > 0) {
            vector<string> connectedRxns = LIBSBMLNETWORK_CPP_NAMESPACE::getConnectedReactionsFor(sbml, 0, sid, m_aliasNum);
            if (!(m_aliasReactionConnections == connectedRxns)) {
                stringstream err;
                err << "The alias node " << m_aliasNum << " for species " << sid + " does not connect to the reaction(s) ";
                for (size_t rxn = 0; rxn < m_aliasReactionConnections.size(); rxn++) {
                    if (rxn > 0) {
                        err << ", ";
                    }
                    err << m_aliasReactionConnections[rxn];
                }
                err << ", but instead connects to ";
                for (size_t rxn = 0; rxn < connectedRxns.size(); rxn++) {
                    if (rxn > 0) {
                        err << ", ";
                    }
                    err << connectedRxns[rxn];
                }
                g_registry.AddWarning(err.str());
                //return true;
            }
        }
        m_aliasNum = -1;
        for (unsigned int a = 0; a < LIBSBMLNETWORK_CPP_NAMESPACE::getNumGraphicalObjects(sbml, sid); a++) {
            if (m_aliasReactionConnections == LIBSBMLNETWORK_CPP_NAMESPACE::getConnectedReactionsFor(sbml, 0, sid, a)) {
                m_aliasNum = a;
            }
        }
        if (m_aliasNum == -1) {
            m_aliasNum = LIBSBMLNETWORK_CPP_NAMESPACE::getNumGraphicalObjects(sbml, sid);
        }
    }
    while (m_aliasNum > 0 && m_aliasNum >= int(LIBSBMLNETWORK_CPP_NAMESPACE::getNumGraphicalObjects(sbml, sid))) {
        var_type parentType = m_parent->GetType();
        if (IsReaction(parentType)) {
            LIBSBMLNETWORK_CPP_NAMESPACE::createAliasReactionGlyph(sbml, sid);
        }
        else if (IsSpecies(parentType)) {
            int ret = LIBSBMLNETWORK_CPP_NAMESPACE::createAliasSpeciesGlyph(sbml, sid, m_aliasReactionConnections[0], 0, false);
            if (ret == -1) {
                g_registry.AddWarning("Unable to add an alias of '" + sid + "' to the reaction '" + m_aliasReactionConnections[0] + "'.  It seems to already connect to that species.");
                break;
            }
            for (size_t rxn = 1; rxn < m_aliasReactionConnections.size(); rxn++) {
                LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGlyphIndexInReactionGlyph(sbml, 0, sid, m_aliasNum, m_aliasReactionConnections[rxn], 0);
            }
        }
        else {
            g_registry.SetError("The variable " + sid + " is not a species or a reaction, so cannot have an alias node.  Unable to set a second " + LayoutTypeToString(m_layout_type) + " for this variable.");
            return true;
        }
    }
    string glyphId = LIBSBMLNETWORK_CPP_NAMESPACE::getId(sbml, 0, sid, m_aliasNum);
    if (m_speciesId == "--") {
        bool ret = false;
        //We need to find the ID that SBMLNetwork has given to the source/sink glyph:
        size_t nreactants = m_parent->GetReaction()->GetLeft()->Size();
        size_t nproducts = m_parent->GetReaction()->GetRight()->Size();
        if (nreactants != 0 && nproducts != 0) {
            g_registry.AddWarning("Attempted to set a source/sink for the reaction " + sid + ", but that reaction has both reactants and products.");
            return false;
        }
        for (int i = 0; i < nreactants + nproducts + 2; i++) {
            string id = LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceEmptySpeciesGlyphId(sbml, sid, m_aliasNum, i);
            if (!id.empty()) {
                m_speciesId = id;
                break;
            }
        }
    }

    if (m_layout_type == lt_sourceSink) {
      bool ret = false;
      for (size_t lw = 0; lw < m_layoutWrappers.size(); lw++) {
        ret = ret || m_layoutWrappers[lw]->TransferLayoutInformationTo(sbml);
      }
      return ret;
    }

    string formstring = m_valFormula.ToSBMLString();
    if (formstring.empty()) {
        //assert(false);
      if (m_layoutWrappers.size() == 0) {
        assert(false);
      }
      for (size_t lw = 0; lw < m_layoutWrappers.size(); lw++) {
        m_layoutWrappers[lw]->TransferLayoutInformationTo(sbml);
      }
      return false;
    }
    ASTNode* astn = parseStringToASTNode(formstring);
    string error = "Unable to set " + sid + "." + LayoutTypeToString(m_layout_type) + " to " + formstring + ".";
    // Handle individual reaction arc colors and line widths.
    LayoutWrapper* lw = static_cast<LayoutWrapper*>(m_parent);
    if (m_parent->GetType() == varLayoutWrapper && lw->m_layout_type == lt_reactionArc) {
      sid = lw->m_parent->GetNameDelimitedBy("_");
      int speciesIndex = LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceIndexAssociatedWithSpecies(sbml, lw->m_speciesId, sid, lw->m_aliasNum, lw->m_speciesIndex);
      switch (m_layout_type) {
      case lt_linecolor:
        return LIBSBMLNETWORK_CPP_NAMESPACE::setStrokeColor(sbml, LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReference(sbml, sid, 0, speciesIndex), formstring) == -1;
      case lt_linewidth:
        return LIBSBMLNETWORK_CPP_NAMESPACE::setStrokeWidth(sbml, LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReference(sbml, sid, 0, speciesIndex), astn->getValue()) == -1;
      case lt_position:
      default:
        stringstream err;
        err << "Cannot set the " << LayoutTypeToString(m_layout_type) << " for a reaction arc.  The only options are the line color ('linecolor') and width ('linewidth').";
        g_registry.AddWarning(err.str());
        return true;
      }
    }
    if (IsPair(m_layout_type)) {
        //The content should already be checked.
        assert(astn->getNumChildren() == 2);
        double xval = astn->getChild(0)->getValue();
        double yval = astn->getChild(1)->getValue();
        int ret1 = 0;
        int ret2 = 0;
        switch (m_layout_type) {
        case lt_position:
            if (!isnan(xval)) {
                ret1 = LIBSBMLNETWORK_CPP_NAMESPACE::setPositionX(sbml, glyphId, xval, false);
            }
            if (!isnan(yval)) {
                ret2 = LIBSBMLNETWORK_CPP_NAMESPACE::setPositionY(sbml, glyphId, yval, false);
            }
            break;
        case lt_size:
            if (!isnan(xval)) {
                if (xval == 0.0) {
                    xval = 0.0001;
                }
                ret1 = LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionWidth(sbml, glyphId, xval, false);
            }
            if (!isnan(yval)) {
                if (yval == 0.0) {
                    yval = 0.0001;
                }
                ret2 = LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionHeight(sbml, glyphId, yval, false);
            }
            break;
        case lt_reactionArc:
        {
            int speciesIndex = LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceIndexAssociatedWithSpecies(sbml, m_speciesId, sid, m_aliasNum, m_speciesIndex);
            if (speciesIndex == -1) {
                if (m_arctype == at_spec || m_arctype == at_rxn) {
                    g_registry.AddWarning("Layout error in model:  unable to draw an arc between the species '" + m_speciesId + "' and the reaction '" + sid + "': '" + m_speciesId + "' is not a participant in that reaction.");
                }
                delete astn;
                return false;
            }
            assert(speciesIndex != -1);
            string role = LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceRole(sbml, sid, m_aliasNum, speciesIndex);
            if (m_segmentIndex > 0) {
                while (m_segmentIndex >= (int)LIBSBMLNETWORK_CPP_NAMESPACE::getNumSpeciesReferenceCurveSegments(sbml, sid, m_aliasNum, speciesIndex)) {
                    LIBSBMLNETWORK_CPP_NAMESPACE::addSpeciesReferenceCubicBezierCurveSegment(sbml, sid, m_aliasNum, speciesIndex);
                }
            }
            switch (m_arctype) {
            case at_spec:
                if (startsAtReaction(role)) {
                    if (!isnan(xval)) {
                        LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentEndPointX(sbml, sid, m_aliasNum, speciesIndex, m_segmentIndex, xval);
                    }
                    if (!isnan(yval)) {
                        LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentEndPointY(sbml, sid, m_aliasNum, speciesIndex, m_segmentIndex, yval);
                    }
                }
                else {
                    assert(!startsAtReaction(role));
                    if (!isnan(xval)) {
                        LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentStartPointX(sbml, sid, m_aliasNum, speciesIndex, m_segmentIndex, xval);
                    }
                    if (!isnan(yval)) {
                        LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentStartPointY(sbml, sid, m_aliasNum, speciesIndex, m_segmentIndex, yval);
                    }
                }
                break;
            case at_rxn:
                if (startsAtReaction(role)) {
                    if (!isnan(xval)) {
                        LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentStartPointX(sbml, sid, m_aliasNum, speciesIndex, m_segmentIndex, xval);
                    }
                    if (!isnan(yval)) {
                        LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentStartPointY(sbml, sid, m_aliasNum, speciesIndex, m_segmentIndex, yval);
                    }
                }
                else {
                    assert(!startsAtReaction(role));
                    if (!isnan(xval)) {
                        LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentEndPointX(sbml, sid, m_aliasNum, speciesIndex, m_segmentIndex, xval);
                    }
                    if (!isnan(yval)) {
                        LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentEndPointY(sbml, sid, m_aliasNum, speciesIndex, m_segmentIndex, yval);
                    }
                }
                break;
            case at_b1:
                if (!isnan(xval)) {
                    LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentBasePoint1X(sbml, sid, m_aliasNum, speciesIndex, m_segmentIndex, xval);
                }
                if (!isnan(yval)) {
                    LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentBasePoint1Y(sbml, sid, m_aliasNum, speciesIndex, m_segmentIndex, yval);
                }
                break;
            case at_b2:
                if (!isnan(xval)) {
                    LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentBasePoint2X(sbml, sid, m_aliasNum, speciesIndex, m_segmentIndex, xval);
                }
                if (!isnan(yval)) {
                    LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentBasePoint2Y(sbml, sid, m_aliasNum, speciesIndex, m_segmentIndex, yval);
                }
                break;
            case at_none:
                assert(false);
                break;
            }
            break;
        }
        default:
            assert(false); //Only the above two are 'IsPair' true
            break;
        }
        if (ret1 == -1 || ret2 == -1) {
            g_registry.AddWarning(error);
            delete astn;
            return false;
        }
    }
    else {
        double lval = util_NaN();
        if (astn) {
            lval = astn->getValue();
        }
        int ret = 0;
        switch (m_layout_type) {
        case lt_position:
        case lt_size:
        case lt_reactionArc:
            assert(false); //Should be IsPair, above
            break;
        case lt_x:
            ret = LIBSBMLNETWORK_CPP_NAMESPACE::setPositionX(sbml, glyphId, lval, false);
            break;
        case lt_y:
            ret = LIBSBMLNETWORK_CPP_NAMESPACE::setPositionY(sbml, glyphId, lval, false);
            break;
        case lt_height:
            ret = LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionHeight(sbml, glyphId, lval, false);
            break;
        case lt_width:
            ret = LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionWidth(sbml, glyphId, lval, false);
            break;
        case lt_color:
            ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFillColor(sbml, glyphId, formstring);
            break;
        case lt_font:
        {
            std::regex underscore_re("_");
            formstring = std::regex_replace(formstring, underscore_re, "-");
            ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontFamily(sbml, glyphId, formstring);
            break;
        }
        case lt_fontsize:
            ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontSize(sbml, glyphId, lval);
            break;
        case lt_fontcolor:
            ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontColor(sbml, glyphId, formstring);
            break;
        case lt_fontstyle:
        case lt_fontweight:
            if (CaselessStrCmp(true, formstring, "bold")) {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontWeight(sbml, glyphId, formstring);
            }
            if (CaselessStrCmp(true, formstring, "italic")) {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontStyle(sbml, glyphId, formstring);
            }
            if (CaselessStrCmp(true, formstring, "normal")) {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontWeight(sbml, glyphId, formstring);
                if (ret == 0) {
                    ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontStyle(sbml, glyphId, formstring);
                }
            }
            if (CaselessStrCmp(true, formstring, "bold_italic")) {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontWeight(sbml, glyphId, "bold");
                if (ret == 0) {
                    ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontStyle(sbml, glyphId, "italic");
                }
            }
            break;
        case lt_linewidth:
            ret = LIBSBMLNETWORK_CPP_NAMESPACE::setStrokeWidth(sbml, glyphId, lval);
            break;
        case lt_linecolor:
            ret = LIBSBMLNETWORK_CPP_NAMESPACE::setStrokeColor(sbml, glyphId, formstring);
            break;
        case lt_shape:
            ret = LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeType(sbml, glyphId, formstring);
            break;
        case lt_sourceSink:
            assert(false); // Should only be parent object, not child.
            break;
        case lt_unknown:
            break;
        }
        if (ret != 0) {
            //g_registry.AddWarning(error);
            delete astn;
            //assert(false);
            return false;

        }
    }

    delete astn;
    return false;
}

bool LayoutWrapper::TransferLayoutInformationTo(SBMLDocument* sbml, const string& group)
{
    assert(group == "species" || group == "reaction" || group == "compartment" || group == "layout");
    string formstring = m_valFormula.ToSBMLString();
    ASTNode* astn = parseStringToASTNode(formstring);
    string error = "Unable to set " + group + "." + LayoutTypeToString(m_layout_type) + " to " + formstring + ".";
    if (IsPair(m_layout_type)) {
        //The content should already be checked.
        assert(astn->getNumChildren() == 2);
        double xval = astn->getChild(0)->getValue();
        double yval = astn->getChild(1)->getValue();
        int ret1 = 0;
        int ret2 = 0;
        assert(m_layout_type == lt_size);
        if (group == "species") {
            ret1 = LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesDimensionWidth(sbml, 0, xval, false);
            ret2 = LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesDimensionHeight(sbml, 0, yval, false);
        }
        else if (group == "compartment") {
            ret1 = LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentDimensionWidth(sbml, 0, xval, false);
            ret2 = LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentDimensionHeight(sbml, 0, yval, false);
        }
        else if (group == "reaction") {
            ret1 = LIBSBMLNETWORK_CPP_NAMESPACE::setReactionDimensionWidth(sbml, 0, xval, false);
            ret2 = LIBSBMLNETWORK_CPP_NAMESPACE::setReactionDimensionHeight(sbml, 0, yval, false);
            double width = LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionWidth(sbml, "J0");
            width = width;
        }
        if (ret1 == -1 || ret2 == -1) {
            g_registry.SetError(error);
            delete astn;
            return true;
        }
    }
    else {
        double lval = util_NaN();
        if (astn) {
            lval = astn->getValue();
        }
        int ret = 0;
        switch (m_layout_type) {
        case lt_position:
        case lt_size:
        case lt_x:
        case lt_y:
        case lt_reactionArc:
        case lt_sourceSink:
            assert(false);
            delete astn;
            return true;
        case lt_height:
            if (group == "species") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesDimensionHeight(sbml, 0, lval, false);
            }
            else if (group == "compartment") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentDimensionHeight(sbml, 0, lval, false);
            }
            else if (group == "reaction") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setReactionDimensionHeight(sbml, 0, lval, false);
            }
            else if (group == "layout") {
                int zero = 0;
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionHeight(sbml, lval);
            }
            else {
                assert(false);
            }
            break;
        case lt_width:
            if (group == "species") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesDimensionWidth(sbml, 0, lval, false);
            }
            else if (group == "compartment") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentDimensionWidth(sbml, 0, lval, false);
            }
            else if (group == "reaction") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setReactionDimensionWidth(sbml, 0, lval, false);
            }
            else if (group == "layout") {
                int zero = 0;
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionWidth(sbml, lval);
            }
            else {
                assert(false);
            }
            break;
        case lt_color:
            if (group == "species") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFillColor(sbml, 0, formstring);
            }
            else if (group == "compartment") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFillColor(sbml, 0, formstring);
            }
            else if (group == "reaction") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setReactionFillColor(sbml, 0, formstring);
            }
            else if (group == "layout") {
                int zero = 0;
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFillColor(sbml, zero, formstring);
            }
            else {
                assert(false);
            }
            break;
        case lt_font:
        {
            std::regex underscore_re("_");
            formstring = std::regex_replace(formstring, underscore_re, "-");
            if (group == "species") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFontFamily(sbml, 0, formstring);
            }
            else if (group == "compartment") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFontFamily(sbml, 0, formstring);
            }
            else if (group == "reaction") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setReactionFontFamily(sbml, 0, formstring);
            }
            else if (group == "layout") {
                int zero = 0;
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontFamily(sbml, zero, formstring);
            }
            else {
                assert(false);
            }
            break;
        }
        case lt_fontsize:
            if (group == "species") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFontSize(sbml, 0, lval);
            }
            else if (group == "compartment") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFontSize(sbml, 0, lval);
            }
            else if (group == "reaction") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setReactionFontSize(sbml, 0, lval);
            }
            else if (group == "layout") {
                int zero = 0;
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontSize(sbml, zero, lval);
            }
            else {
                assert(false);
            }
            break;
        case lt_fontcolor:
            if (group == "species") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFontColor(sbml, 0, formstring);
            }
            else if (group == "compartment") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFontColor(sbml, 0, formstring);
            }
            else if (group == "reaction") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setReactionFontColor(sbml, 0, formstring);
            }
            else if (group == "layout") {
                int zero = 0;
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontColor(sbml, zero, formstring);
            }
            else {
                assert(false);
            }
            break;
        case lt_fontstyle:
        case lt_fontweight:
            if (CaselessStrCmp(true, formstring, "bold")) {
                if (group == "species") {
                    ret = LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFontWeight(sbml, 0, formstring);
                }
                else if (group == "compartment") {
                    ret = LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFontWeight(sbml, 0, formstring);
                }
                else if (group == "reaction") {
                    ret = LIBSBMLNETWORK_CPP_NAMESPACE::setReactionFontWeight(sbml, 0, formstring);
                }
                else if (group == "layout") {
                    int zero = 0;
                    ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontWeight(sbml, zero, formstring);
                }
                else {
                    assert(false);
                }
            }
            if (CaselessStrCmp(true, formstring, "italic")) {
                if (group == "species") {
                    ret = LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFontStyle(sbml, 0, formstring);
                }
                else if (group == "compartment") {
                    ret = LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFontStyle(sbml, 0, formstring);
                }
                else if (group == "reaction") {
                    ret = LIBSBMLNETWORK_CPP_NAMESPACE::setReactionFontStyle(sbml, 0, formstring);
                }
                else if (group == "layout") {
                    int zero = 0;
                    ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontStyle(sbml, zero, formstring);
                }
                else {
                    assert(false);
                }
            }
            if (CaselessStrCmp(true, formstring, "normal")) {
                if (group == "species") {
                    ret = LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFontWeight(sbml, 0, formstring);
                }
                else if (group == "compartment") {
                    ret = LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFontWeight(sbml, 0, formstring);
                }
                else if (group == "reaction") {
                    ret = LIBSBMLNETWORK_CPP_NAMESPACE::setReactionFontWeight(sbml, 0, formstring);
                }
                else if (group == "layout") {
                    int zero = 0;
                    ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontWeight(sbml, zero, formstring);
                }
                else {
                    assert(false);
                }
                if (ret == 0) {
                    if (group == "species") {
                        ret = LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFontStyle(sbml, 0, formstring);
                    }
                    else if (group == "compartment") {
                        ret = LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFontStyle(sbml, 0, formstring);
                    }
                    else if (group == "reaction") {
                        ret = LIBSBMLNETWORK_CPP_NAMESPACE::setReactionFontStyle(sbml, 0, formstring);
                    }
                    else if (group == "layout") {
                        int zero = 0;
                        ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontStyle(sbml, zero, formstring);
                    }
                    else {
                        assert(false);
                    }
                }
            }
            if (CaselessStrCmp(true, formstring, "bold_italic")) {
                if (group == "species") {
                    ret = LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFontWeight(sbml, 0, "bold");
                }
                else if (group == "compartment") {
                    ret = LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFontWeight(sbml, 0, "bold");
                }
                else if (group == "reaction") {
                    ret = LIBSBMLNETWORK_CPP_NAMESPACE::setReactionFontWeight(sbml, 0, "bold");
                }
                else if (group == "layout") {
                    int zero = 0;
                    ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontWeight(sbml, zero, "bold");
                }
                else {
                    assert(false);
                }
                if (ret == 0) {
                    if (group == "species") {
                        ret = LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFontStyle(sbml, 0, "italic");
                    }
                    else if (group == "compartment") {
                        ret = LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFontStyle(sbml, 0, "italic");
                    }
                    else if (group == "reaction") {
                        ret = LIBSBMLNETWORK_CPP_NAMESPACE::setReactionFontStyle(sbml, 0, "italic");
                    }
                    else if (group == "layout") {
                        int zero = 0;
                        ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontStyle(sbml, zero, "italic");
                    }
                    else {
                        assert(false);
                    }
                }
            }
            break;
        case lt_linewidth:
            if (group == "species") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesStrokeWidth(sbml, 0, lval);
            }
            else if (group == "compartment") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentStrokeWidth(sbml, 0, lval);
            }
            else if (group == "reaction") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setReactionStrokeWidth(sbml, 0, lval);
            }
            else if (group == "layout") {
                int zero = 0;
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setStrokeWidth(sbml, zero, lval);
            }
            else {
                assert(false);
            }
            break;
        case lt_linecolor:
            if (group == "species") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesStrokeColor(sbml, 0, formstring);
            }
            else if (group == "compartment") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentStrokeColor(sbml, 0, formstring);
            }
            else if (group == "reaction") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setReactionStrokeColor(sbml, 0, formstring);
            }
            else if (group == "layout") {
                int zero = 0;
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setStrokeColor(sbml, zero, formstring);
            }
            else {
                assert(false);
            }
            break;
        case lt_shape:
            if (group == "species") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeType(sbml, 0, formstring);
            }
            else if (group == "compartment") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeType(sbml, 0, formstring);
            }
            else if (group == "reaction") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeType(sbml, 0, formstring);
            }
            else if (group == "layout") {
                assert(false); //Shouldn't be able to set a default shape.
                int zero = 0;
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeType(sbml, zero, formstring);
            }
            else {
                assert(false);
            }
            break;
        case lt_unknown:
            break;
        }
        if (ret == -1) {
            g_registry.AddWarning(error);
            delete astn;
            return true;
        }
    }

    delete astn;
    return false;
}

bool LayoutWrapper::HasLayoutPositionInfo() const
{
    switch (m_layout_type) {
    case lt_position:
    case lt_x:
    case lt_y:
    case lt_reactionArc:
    case lt_sourceSink:
        return true;
    case lt_size:
    case lt_height:
    case lt_width:
    case lt_color:
    case lt_font:
    case lt_fontsize:
    case lt_fontcolor:
    case lt_fontstyle:
    case lt_fontweight:
    case lt_linewidth:
    case lt_linecolor:
    case lt_shape:
    case lt_unknown:
        return false;
    }
    assert(false);
    return false;
}

bool LayoutWrapper::setSpeciesId(const std::string& name)
{
    m_speciesId = name;
    return false;
}

void LayoutWrapper::setSpeciesIndex(int index)
{
    m_speciesIndex = index;
}

void LayoutWrapper::setSegmentIndex(int index)
{
    m_segmentIndex = index;
}

bool LayoutWrapper::setArcType(const std::string* type)
{
    if (CaselessStrCmp(true, *type, "species_end")) {
        m_arctype = at_spec;
        return false;
    }
    if (CaselessStrCmp(true, *type, "b1")) {
        m_arctype = at_b1;
        return false;
    }
    if (CaselessStrCmp(true, *type, "b2")) {
        m_arctype = at_b2;
        return false;
    }
    if (CaselessStrCmp(true, *type, "rxn_end")) {
        m_arctype = at_rxn;
        return false;
    }

    return true;
}

bool LayoutWrapper::setArcNumber(const std::string* type)
{
    regex arcNum("^arc([0-9]+)$");
    std::smatch m;
    if (regex_search(*type, m, arcNum)) {
        m_speciesIndex = stoi(m[1].str()) - 1;
        return false;
    }
    return true;
}

bool LayoutWrapper::setSegmentNumber(const std::string* type)
{
    regex segNum("^seg([0-9]+)$");
    std::smatch m;
    if (regex_search(*type, m, segNum)) {
        m_segmentIndex = stoi(m[1].str()) - 1;
        return false;
    }
    return true;
}

bool LayoutWrapper::setArcType(arc_type type)
{
    m_arctype = type;
    return false;
}

bool LayoutWrapper::setAliasNum(int aliasNum)
{
    if (aliasNum < 0) {
        return true;
    }
    m_aliasNum = aliasNum;
    return false;
}

bool LayoutWrapper::setAliasReactionConnections(std::vector<std::string> rxnids)
{
    m_aliasReactionConnections = rxnids;
    return false;
}

Variable* LayoutWrapper::GetSubVariable(const std::string* name)
{
    layout_type ltype = lt_unknown;
    int aliasNum = -1;
    GetLayoutTypeAndNumFromString(*name, ltype, aliasNum);
    if (ltype != lt_unknown) {
        if (m_speciesId == "--") {
            m_layout_type = lt_sourceSink;
        }
        return AddOrGetLayoutWrapper(ltype, aliasNum, m_aliasReactionConnections);
    }
    if (m_layout_type == lt_reactionArc) {
        if (setArcType(name)) {
            // It wasn't 'species_end', 'rxn_end', 'b1', or 'b2', so try 'arc#':
            if (setArcNumber(name)) {
                // It wasn't 'arc#', so try 'seg#':
                if (setSegmentNumber(name)) {
                    g_registry.SetError("Unable to define a reaction arc for " + m_parent->GetNameDelimitedBy(".") + " with the term '" + *name + "'.");
                    return NULL;
                }
            }
        }
        return this;
    }
    if (IsSpecies(m_parent->GetType())) {
        vector<string> id = m_parent->GetName();
        id.pop_back();
        id.push_back(*name);
        Module* mod = g_registry.CurrentModule();
        if (!mod) {
            g_registry.SetError("Unable to find the module of the variable " + m_parent->GetNameDelimitedBy(".") + ".");
            return NULL;
        }
        Variable* subvar = mod->GetVariable(id);
        if (!subvar) {
            g_registry.SetError("Unable to find a reaction with the id '" + *name + "' in the same module as " + m_parent->GetNameDelimitedBy(".") + ".");
            return NULL;
        }
        if (!IsReaction(subvar->GetType())) {
            g_registry.SetError("The variable '" + *name + "' is not a reaction.  To create an alias species of " + m_parent->GetNameDelimitedBy(".") + ", it must be defined by the reactions it connects to.");
            return NULL;
        }
        m_aliasReactionConnections.push_back(*name);
        return this;
    }
    g_registry.SetError("Only species and reaction layouts are defined by subvariables.  Reaction arcs are defined by the reaction and species they connect, as in 'J0.S1.species_end', and species alias nodes are defined with the list of reactions they connect to, as in 'S1.position.J0.J1'.  The variable '" + m_parent->GetNameDelimitedBy(".") + "' is not a species, .");
    return NULL;
}
