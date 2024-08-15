#include "LayoutWrapper.h"
#include "module.h"
#include "registry.h"
#include "stringx.h"
#include "regex"
#ifdef LIBSBML_HAS_PACKAGE_DISTRIB
#include <sbml/packages/layout/sbml/Layout.h>
#include <sbml/packages/layout/extension/LayoutModelPlugin.h>
#endif
#include <libsbmlnetwork_sbmldocument.h>
#include <libsbmlnetwork_sbmldocument_layout.h>
#include <libsbmlnetwork_sbmldocument_render.h>
#include <libsbmlnetwork_render_helpers.h>

using namespace std;
using namespace libsbml;

LayoutWrapper::LayoutWrapper(Variable* parent, layout_type type)
    : Variable()
    , m_parent(parent)
    , m_layout_type(type)
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

Variable* LayoutWrapper::GetSameVariable()
{
    return m_parent;
}

const Variable* LayoutWrapper::GetSameVariable() const
{
    return m_parent;
}

bool LayoutWrapper::SetFormula(Formula* formula, bool isObjective)
{
    if (Variable::SetFormula(formula, isObjective)) {
        return true;
    }

    if (IsPair(m_layout_type)) {
        //Only Vectors of length 2 are allowed for these types
        //We're only going to be able to check this in SBML mode
#ifndef NSBML
        ASTNode* astn = parseStringToASTNode(formula->ToSBMLString());
        if (!astn || astn->getType() != AST_LINEAR_ALGEBRA_VECTOR || astn->getNumChildren() != 2) {
            g_registry.SetError("Unable to set the value of '" + GetNameDelimitedBy(".") + "' to be '" + formula->ToDelimitedStringWithEllipses(".") + "':  an layout parameter of type " + LayoutTypeToString(m_layout_type) + " must be a vector of length two, marked with curly brackets (i.e. '{150, 200}').");
            delete astn;
            return true;
        }
        for (unsigned int c = 0; c < 2; c++) {
            ASTNodeType_t ctype = astn->getChild(c)->getType();
            if (!astn->getChild(c)->isNumber()) {
                g_registry.SetError("Unable to set the value of '" + GetNameDelimitedBy(".") + "' to be '" + formula->ToDelimitedStringWithEllipses(".") + "':  an layout parameter of type " + LayoutTypeToString(m_layout_type) + " must be a vector of length two, and each element of the vector may only be a value (i.e. '{150, 200}').");
                delete astn;
                return true;
            }
        }
        if (astn->getChild(0)->isSetUnits() || astn->getChild(1)->isSetUnits()) {
            g_registry.SetError("Unable to set the value of '" + GetNameDelimitedBy(".") + "' to be '" + formula->ToDelimitedStringWithEllipses(".") + "':  units may not be used for layout positions.");
            delete astn;
            return true;
        }
        delete astn;
#endif
        return false;
    }
    else {
        string formstring = m_valFormula.ToSBMLString();
        ASTNode* astn = parseStringToASTNode(formstring);
        double lval = astn->getValue();
        string strval = "";
        if (astn->getType() == AST_NAME) {
            strval = astn->getName();
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
                if (astn == NULL || !astn->isNumber()) {
                    g_registry.SetError("Unable to set the value of '" + GetNameDelimitedBy(".") + "' to '" + formula->ToDelimitedStringWithEllipses(".") + "'.  It may only be set to a numerical value.");
                    return true;
                }
                break;
            case lt_color:
            case lt_fontcolor:
            case lt_linecolor:
                if (!LIBSBMLNETWORK_CPP_NAMESPACE::isValidColorValue(formstring)) {
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

Variable* LayoutWrapper::GetParent()
{
    return m_parent;
}

string LayoutWrapper::GetNameDelimitedBy(string cc) const
{
    if (m_parent) {
        return m_parent->GetNameDelimitedBy(cc) + cc + LayoutTypeToString(m_layout_type);
    }
    else {
        return Variable::GetNameDelimitedBy(cc);
    }
}

bool LayoutWrapper::Synchronize(Variable* clone, const Variable* conversionFactor)
{
    g_registry.SetError("Unable to synchronize two symbols when one of them ('" + GetNameDelimitedBy(".") + "') is an layout term.");
    return true;
}

string LayoutWrapper::CreateLayoutParamsAntimonySyntax(const string& indent) const
{
    string ret = "";
    if (!m_valFormula.IsEmpty()) {
        ret = indent + GetNameDelimitedBy(".") + " = " + m_valFormula.ToDelimitedStringWithEllipses(".") + "\n";
    }
    if (!m_displayname.empty()) {
        ret += indent + GetNameDelimitedBy(".") + " is \"" + m_displayname + "\"\n";
    }
    return ret;
}

bool LayoutWrapper::TransferLayoutInformationTo(SBMLDocument* sbml) const
{
    string sid = m_parent->GetNameDelimitedBy("_");
    string formstring = m_valFormula.ToSBMLString();
    ASTNode* astn = parseStringToASTNode(formstring);
    string error = "Unable to set " + sid + "." + LayoutTypeToString(m_layout_type) + " to " + formstring + ".";
    if (IsPair(m_layout_type)) {
        //The content should already be checked.
        assert(astn->getNumChildren() == 2);
        double xval = astn->getChild(0)->getValue();
        double yval = astn->getChild(1)->getValue();
        int ret1 = 0;
        int ret2 = 0;
        switch (m_layout_type) {
        case lt_position:
            ret1 = LIBSBMLNETWORK_CPP_NAMESPACE::setPositionX(sbml, sid, xval);
            ret2 = LIBSBMLNETWORK_CPP_NAMESPACE::setPositionY(sbml, sid, yval);
            break;
        case lt_size:
            ret1 = LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionWidth(sbml, sid, xval);
            ret2 = LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionHeight(sbml, sid, yval);
            break;
        //case lt_start:
        //case lt_end:
        //case lt_mid1:
        //case lt_mid2:
        //    assert(false); //Probably don't actually set these.
        //    break;
        }
        if (ret1 == -1 || ret2 == -1) {
            g_registry.SetError(error);
            return true;
        }
    }
    else {
        double lval = astn->getValue();
        int ret = 0;
        switch (m_layout_type) {
        case lt_x:
            ret = LIBSBMLNETWORK_CPP_NAMESPACE::setPositionX(sbml, sid, lval);
            break;
        case lt_y:
            ret = LIBSBMLNETWORK_CPP_NAMESPACE::setPositionY(sbml, sid, lval);
            break;
        case lt_height:
            ret = LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionHeight(sbml, sid, lval);
            break;
        case lt_width:
            ret = LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionWidth(sbml, sid, lval);
            break;
        case lt_color:
            ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFillColor(sbml, sid, formstring);
            break;
        case lt_font:
        {
            std::regex underscore_re("_");
            formstring = std::regex_replace(formstring, underscore_re, "-");
            ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontFamily(sbml, sid, formstring);
            break;
        }
        case lt_fontsize:
            ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontSize(sbml, sid, lval);
            break;
        case lt_fontcolor:
            ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontColor(sbml, sid, formstring);
            break;
        case lt_fontstyle:
        case lt_fontweight:
            if (CaselessStrCmp(false, formstring, "bold")) {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontWeight(sbml, sid, formstring);
            }
            if (CaselessStrCmp(false, formstring, "italic")) {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontStyle(sbml, sid, formstring);
            }
            if (CaselessStrCmp(false, formstring, "normal")) {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontWeight(sbml, sid, formstring);
                if (ret == 0) {
                    ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontStyle(sbml, sid, formstring);
                }
            }
            if (CaselessStrCmp(false, formstring, "bold_italic")) {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontWeight(sbml, sid, "bold");
                if (ret == 0) {
                    ret = LIBSBMLNETWORK_CPP_NAMESPACE::setFontStyle(sbml, sid, "italic");
                }
            }
            break;
        case lt_linewidth:
            ret = LIBSBMLNETWORK_CPP_NAMESPACE::setStrokeWidth(sbml, sid, lval);
            break;
        case lt_linecolor:
            ret = LIBSBMLNETWORK_CPP_NAMESPACE::setStrokeColor(sbml, sid, formstring);
            break;
        case lt_shape:
            ret = LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeType(sbml, sid, formstring);
            break;
        case lt_unknown:
            break;
        }
    }


    return false;
}

bool LayoutWrapper::TransferLayoutInformationTo(SBMLDocument* sbml, const string& group) const
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
            ret1 = LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesDimensionWidth(sbml, 0, xval);
            //double S1width = LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionWidth(sbml, "S1");
            ret2 = LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesDimensionHeight(sbml, 0, yval);
        }
        else if (group == "compartment") {
            ret1 = LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentDimensionWidth(sbml, 0, xval);
            ret2 = LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentDimensionHeight(sbml, 0, yval);
        }
        else if (group == "reaction") {
            ret1 = LIBSBMLNETWORK_CPP_NAMESPACE::setReactionDimensionWidth(sbml, 0, xval);
            ret2 = LIBSBMLNETWORK_CPP_NAMESPACE::setReactionDimensionHeight(sbml, 0, yval);
        }
        if (ret1 == -1 || ret2 == -1) {
            g_registry.SetError(error);
            return true;
        }
    }
    else {
        double lval = astn->getValue();
        int ret = 0;
        switch (m_layout_type) {
        case lt_x:
        case lt_y:
            assert(false);
            return true;
        case lt_height:
            if (group == "species") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesDimensionHeight(sbml, 0, lval);
            }
            else if (group == "compartment") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentDimensionHeight(sbml, 0, lval);
            }
            else if (group == "reaction") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setReactionDimensionHeight(sbml, 0, lval);
            }
            else if (group == "layout") {
                int zero = 0;
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionHeight(sbml, zero, lval);
            }
            else {
                assert(false);
            }
            break;
        case lt_width:
            if (group == "species") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesDimensionWidth(sbml, 0, lval);
            }
            else if (group == "compartment") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentDimensionWidth(sbml, 0, lval);
            }
            else if (group == "reaction") {
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setReactionDimensionWidth(sbml, 0, lval);
            }
            else if (group == "layout") {
                int zero = 0;
                ret = LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionWidth(sbml, zero, lval);
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
            if (CaselessStrCmp(false, formstring, "bold")) {
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
            if (CaselessStrCmp(false, formstring, "italic")) {
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
            if (CaselessStrCmp(false, formstring, "normal")) {
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
            if (CaselessStrCmp(false, formstring, "bold_italic")) {
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
    }


    return false;
}

bool LayoutWrapper::HasLayoutPositionInfo() const
{
    switch (m_layout_type) {
    case lt_position:
    case lt_x:
    case lt_y:
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
