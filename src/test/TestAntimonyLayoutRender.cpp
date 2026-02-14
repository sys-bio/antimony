/**
 * \file    TestAntimonyLayoutRender.c
 * \brief   Test Antimony's Layout and Render constructs.
 * \author  Lucian Smith
 * ---------------------------------------------------------------------- -->*/

#include "libutil.h"
#include "antimony_api.h"
#include "registry.h"
#include <sbml/SBMLTypes.h>
#include "sbmlnetwork/libsbmlnetwork_layout_helpers.h"
#include "sbmlnetwork/libsbmlnetwork_sbmldocument.h"
#include "sbmlnetwork/libsbmlnetwork_sbmldocument_layout.h"
#include "sbmlnetwork/libsbmlnetwork_sbmldocument_render.h"


#include <string>
#include <check.h>

using namespace std;
using namespace libsbml;

BEGIN_C_DECLS

extern char *TestDataDirectory;

libsbml::SBMLDocument* translateAntimony(const string& model)
{
    g_registry.SetCC("__");
    // load document
    string dir(TestDataDirectory);
    long ret = loadAntimonyString(model.c_str());
    fail_unless(ret != -1);
    char* atosbml = getCompSBMLString(NULL);
    fail_unless(atosbml != NULL);
    libsbml::SBMLDocument* doc = LIBSBMLNETWORK_CPP_NAMESPACE::readSBML(atosbml);
    clearPreviousLoads();
    return doc;
}


string translateAntimonyFromDoc(libsbml::SBMLDocument* doc)
{
    g_registry.SetCC("__");
    // load document
    string dir(TestDataDirectory);
    long ret = loadSBMLString(writeSBMLToStdString(doc).c_str());
    fail_unless(ret != -1);
    char* sbml2a = getAntimonyString(NULL);
    fail_unless(sbml2a != NULL);
    clearPreviousLoads();
    return sbml2a;
}


START_TEST(test_basic_autolayout)
{
    string model =
        "S1->S2;\n"
        "S2->S3;\n"
        "model.layout = on"
        ;

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S1") != 0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S1") != 0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S2") != 0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S2") != 0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S3") != 0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S3") != 0);
    delete doc;
}
END_TEST

START_TEST(test_basic_positions)
{
    string model =
        "S1->S2;\n"
        "S1.pos = {52, 80}\n"
        "S2.x = 86\n"
        "S2.y = 73\n"
        ;

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S1") == 52);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S1") == 80);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S2") == 86);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S2") == 73);
    delete doc;
}
END_TEST

START_TEST(test_basic_sizes)
{
    string model =
        "S1->S2;\n"
        "S1.size = {52, 80}\n"
        "S2.width = 86\n"
        "S2.height = 73\n"
        ;

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionWidth(doc, "S1") == 52.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionHeight(doc, "S1") == 80.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionWidth(doc, "S2") == 86.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionHeight(doc, "S2") == 73.0);
    delete doc;
}
END_TEST

START_TEST(test_maxEdges)
{
    string model =
        "S1->S2;\n"
        "S1->S3;\n"
        "S1->S4;\n"
        "S1->S5;\n"
        "S1->S6;\n"
        "S1->S7;\n"
        "S1->S8;\n"
        "model.autolayout.maxNumConnectedEdges = 7\n"
        ;

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getNumSpeciesGlyphs(doc, "S1") == 1);
    delete doc;

    string model2 =
        "S1->S2;\n"
        "S1->S3;\n"
        "S1->S4;\n"
        "S1->S5;\n"
        "S1->S6;\n"
        "S1->S7;\n"
        "S1->S8;\n"
        "model.layout = on\n"
        ;

    doc = translateAntimony(model2);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getNumSpeciesGlyphs(doc, "S1") == 3);
    delete doc;
}
END_TEST

//START_TEST(test_useNameAsTextLabel)
//{
//    string model =
//        "S1->S2;\n"
//        "S1 is \"Species 1\"\n"
//        "model.autolayout.useNameAsTextLabel = false\n"
//        ;
//
//    libsbml::SBMLDocument* doc = translateAntimony(model);
//    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getText(doc, "S1") == "S1");
//    delete doc;
//
//    string model2 =
//        "S1->S2;\n"
//        "S1 is \"Species 1\"\n"
//        "model.layout = on\n"
//        ;
//
//    doc = translateAntimony(model2);
//    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getText(doc, "S1") == "Species 1");
//    delete doc;
//}
//END_TEST

START_TEST(test_setLayoutStyle)
{
    string model =
        "S1->S2;\n"
        "model.layout = on\n"
        "model.layout.style = power\n"
        ;

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getBackgroundColor(doc) == "white");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeType(doc) == "rectangle");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentStrokeColor(doc) == "mandy");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentStrokeWidth(doc) == 3.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFillColor(doc) == "pewter");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFontColor(doc) == "gondola");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFontSizeAsDouble(doc) == 10);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeType(doc) == "rectangle");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesFillColor(doc) == "carnation");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesStrokeColor(doc) == "gondola");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesStrokeWidth(doc) == 3.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesFontColor(doc) == "gondola");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesFontSizeAsDouble(doc) == 24.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getReactionStrokeColor(doc) == "gondola");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getReactionStrokeWidth(doc) == 3.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getReactionFontColor(doc) == "gondola");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getReactionFontSizeAsDouble(doc) == 12.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingStrokeColor(doc, 0) == "gondola");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingStrokeWidth(doc) == 3.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingFillColor(doc) == "gondola");

    delete doc;
}
END_TEST

START_TEST(test_layout_size)
{
    string model =
        "S1->S2;\n"
        "model.layout.size = {1234, 1432}\n"
        ;

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionWidth(doc) == 1234.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionHeight(doc) == 1432.0);
    delete doc;

    model =
        "S1->S2;\n"
        "model.layout.width = 1234\n"
        "model.layout.height = 1432\n"
        ;

    doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionWidth(doc) == 1234.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionHeight(doc) == 1432.0);
    delete doc;
}
END_TEST

START_TEST(test_align_top)
{
    string model =
        "S1->S2;\n"
        "S2->S3;\n"
        "S3->S4;\n"
        "model.layout.size = {1000, 1000}\n"
        "model.layout.align_top = {S1, S2, S3}\n"
        ;

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S1") == LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S2"));
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S2") == LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S3"));
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S1") < 300);
    //cout << LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S1") << endl;
    delete doc;
}
END_TEST

START_TEST(test_align_bottom)
{
    string model =
        "S1->S2;\n"
        "S2->S3;\n"
        "S3->S4;\n"
        "model.layout.size = {1000, 1000}\n"
        "model.layout.align_bottom = {S1, S2, S3}\n"
        ;

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S1") == LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S2"));
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S2") == LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S3"));
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S1") > 700);
    delete doc;
}
END_TEST

START_TEST(test_align_hCenter)
{
    string model =
        "S1->S2;\n"
        "S2->S3;\n"
        "S3->S4;\n"
        "model.layout.size = {1000, 1000}\n"
        "model.layout.align_hcenter = {S1, S2, S3}\n"
        ;

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S1") == LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S2"));
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S2") == LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S3"));
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S1") > 400);
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S1") < 600);
    delete doc;
}
END_TEST

START_TEST(test_align_right)
{
    string model =
        "S1->S2;\n"
        "S2->S3;\n"
        "S3->S4;\n"
        "model.layout.size = {1000, 1000}\n"
        "model.layout.align_right = {S1, S2, S3}\n"
        ;

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S1") == LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S2"));
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S2") == LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S3"));
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S1") > 700);
    delete doc;
}
END_TEST

START_TEST(test_align_left)
{
    string model =
        "S1->S2;\n"
        "S2->S3;\n"
        "S3->S4;\n"
        "model.layout.size = {1000, 1000}\n"
        "model.layout.align_left = {S1, S2, S3}\n"
        ;

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S1") == LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S2"));
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S2") == LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S3"));
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S1") < 300);
    delete doc;
}
END_TEST

START_TEST(test_align_vCenter)
{
    string model =
        "S1->S2;\n"
        "S2->S3;\n"
        "S3->S4;\n"
        "model.layout.size = {1000, 1000}\n"
        "model.layout.align_vcenter = {S1, S2, S3}\n"
        ;

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S1") == LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S2"));
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S2") == LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S3"));
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "s1") > 400);
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "s1") < 600);
    delete doc;
}
END_TEST

START_TEST(test_whole_model_settings)
{
    string model =
        "S1->S2;\n"
        "model.layout.background = orange\n"
        "model.layout.color = khaki\n"
        "model.layout.linecolor = azure\n"
        "model.layout.fontcolor = coral\n"
        "model.layout.linewidth = 32\n"
        "model.layout.font = monospace\n"
        "model.layout.fontsize = 4\n"
        "model.layout.fontstyle = italic\n"
        ;

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getBackgroundColor(doc) == "orange");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFillColor(doc) == "khaki");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesFillColor(doc) == "khaki");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getReactionFillColor(doc) == "khaki");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentStrokeColor(doc) == "azure");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesStrokeColor(doc) == "azure");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getReactionStrokeColor(doc) == "azure");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFontColor(doc) == "coral");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesFontColor(doc) == "coral");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getReactionFontColor(doc) == "coral");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentStrokeWidth(doc) == 32.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesStrokeWidth(doc) == 32.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getReactionStrokeWidth(doc) == 32.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFontFamily(doc) == "monospace");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesFontFamily(doc) == "monospace");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getReactionFontFamily(doc) == "monospace");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFontSizeAsDouble(doc) == 4.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesFontSizeAsDouble(doc) == 4.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getReactionFontSizeAsDouble(doc) == 4.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFontStyle(doc) == "italic");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesFontStyle(doc) == "italic");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getReactionFontStyle(doc) == "italic");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFontWeight(doc) == "bold");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesFontWeight(doc) == "normal");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getReactionFontWeight(doc) == "normal");
    delete doc;
}
END_TEST

START_TEST(test_species_settings)
{
    string model =
        "S1->S2;\n"
        "species.size = {42, 55}\n"
        "species.color = khaki\n"
        "species.linecolor = azure\n"
        "species.fontcolor = coral\n"
        "species.linewidth = 32\n"
        "species.font = monospace\n"
        "species.fontsize = 4\n"
        "species.fontstyle = italic\n"
        ;

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionWidth(doc, "S1") == 42.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionHeight(doc, "S1") == 55.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionWidth(doc, "S2") == 42.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionHeight(doc, "S2") == 55.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesFillColor(doc) == "khaki");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesStrokeColor(doc) == "azure");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesFontColor(doc) == "coral");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesStrokeWidth(doc) == 32.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesFontFamily(doc) == "monospace");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesFontSizeAsDouble(doc) == 4.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesFontStyle(doc) == "italic");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesFontWeight(doc) == "normal");
    delete doc;
}
END_TEST

START_TEST(test_compartment_settings)
{
    string model =
        "species S1 in C, S2 in C\n"
        "S1->S2;\n"
        "compartment.size = {420, 550}\n"
        "compartment.color = khaki\n"
        "compartment.linecolor = azure\n"
        "compartment.fontcolor = coral\n"
        "compartment.linewidth = 32\n"
        "compartment.font = monospace\n"
        "compartment.fontsize = 4\n"
        "compartment.fontstyle = italic\n"
        ;

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionWidth(doc, "C") == 420.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionHeight(doc, "C") == 550.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFillColor(doc) == "khaki");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentStrokeColor(doc) == "azure");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFontColor(doc) == "coral");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentStrokeWidth(doc) == 32.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFontFamily(doc) == "monospace");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFontSizeAsDouble(doc) == 4.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFontStyle(doc) == "italic");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFontWeight(doc) == "bold");
    delete doc;
}
END_TEST

START_TEST(test_reaction_settings)
{
    string model =
        "J0: S1->S2;\n"
        "reaction.size = {420, 550}\n"
        "reaction.color = khaki\n"
        "reaction.linecolor = azure\n"
        "reaction.fontcolor = coral\n"
        "reaction.linewidth = 32\n"
        "reaction.font = monospace\n"
        "reaction.fontsize = 4\n"
        "reaction.fontstyle = italic\n"
        ;

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionWidth(doc, "J0") == 420.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionHeight(doc, "J0") == 550.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getReactionFillColor(doc) == "khaki");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getReactionStrokeColor(doc) == "azure");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getReactionFontColor(doc) == "coral");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getReactionStrokeWidth(doc) == 32.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getReactionFontFamily(doc) == "monospace");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getReactionFontSizeAsDouble(doc) == 4.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getReactionFontStyle(doc) == "italic");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getReactionFontWeight(doc) == "normal");
    delete doc;
}
END_TEST

START_TEST(test_locations_pos)
{
    string model =
        "J0: S1->S2;\n"
        "S1.pos= {120, 250}\n"
        "S2.pos= {420, 550}\n"
        "J0.pos= {270, 400}\n"
        "J0.size = {22, 33}\n"
        ;

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S1") == 120.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S1") == 250.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S2") == 420.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S2") == 550.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "J0") == 270.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "J0") == 400.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionWidth(doc, "J0") == 22.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionHeight(doc, "J0") == 33.0);
    delete doc;
}
END_TEST

START_TEST(test_locations_xy)
{
    string model =
        "J0: S1->S2;\n"
        "S1.x= 120\n"
        "S2.x= 420\n"
        "J0.x= 270\n"
        "S1.y= 250\n"
        "S2.y= 550\n"
        "J0.y= 400\n"
        ;

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S1") == 120.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S1") == 250.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S2") == 420.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S2") == 550.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "J0") == 270.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "J0") == 400.0);
    delete doc;
}
END_TEST


START_TEST(test_individual_render)
{
    string model =
        "J0: S1->S2;\n"
        "S2.color = khaki\n"
        "S2.linecolor = azure\n"
        "S2.fontcolor = coral\n"
        "S2.linewidth = 32\n"
        "S2.font = monospace\n"
        "S2.fontsize = 4\n"
        "S2.fontstyle = italic\n"
        ;

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getFillColor(doc, "S2") == "khaki");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getStrokeColor(doc, "S2") == "azure");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getFontColor(doc, "S2") == "coral");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getStrokeWidth(doc, "S2") == 32.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getFontFamily(doc, "S2") == "monospace");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getFontSizeAsDouble(doc, "S2") == 4.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getFontStyle(doc, "S2") == "italic");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getFontWeight(doc, "S2") == "normal");

    delete doc;
}
END_TEST


START_TEST(test_control_points)
{
    string model =
        "J0: S1->S2;\n"
        "S1.position = { 560, 0 }\n"
        "S2.position = { 30, 37.5 }\n"
        "J0.position = { 318.13, 29.25 }\n"
        "J0.S1.species_end = { 550.02, 20.83 }\n"
        "J0.S1.b1 = { 364.9, 33.93 }\n"
        "J0.S1.b2 = { 350, 35 }\n"
        "J0.S2.species_end = { 99.98, 52.67 }\n"
        "J0.S2.b1 = { 285.1, 39.57 }\n"
        "J0.S2.b2 = { 290, 40 }\n";

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S1") == 560);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S1") == 0.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S2") == 30.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S2") == 37.5);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "J0") == 318.13);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "J0") == 29.25);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointX(doc, "J0", 0, 0, 0) == 550.02);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointY(doc, "J0", 0, 0, 0) == 20.83);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointX(doc, "J0", 0, 0, 0) == 318.13 + 10);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointY(doc, "J0", 0, 0, 0) == 29.25 + 10);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1X(doc, "J0", 0, 0, 0) == 364.9);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1Y(doc, "J0", 0, 0, 0) == 33.93);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2X(doc, "J0", 0, 0, 0) == 350);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2Y(doc, "J0", 0, 0, 0) == 35);

    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointX(doc, "J0", 0, 1, 0) == 99.98);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointY(doc, "J0", 0, 1, 0) == 52.67);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointX(doc, "J0", 0, 1, 0) == 318.13 + 10);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointY(doc, "J0", 0, 1, 0) == 29.25 + 10);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1X(doc, "J0", 0, 1, 0) == 285.1);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1Y(doc, "J0", 0, 1, 0) == 39.57);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2X(doc, "J0", 0, 1, 0) == 290);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2Y(doc, "J0", 0, 1, 0) == 40);

    delete doc;
}
END_TEST


START_TEST(test_control_points_off_reaction)
{
    string model =
        "J0: S1->S2;\n"
        "S1.position = { 560, 0 }\n"
        "S2.position = { 30, 37.5 }\n"
        "J0.position = { 318.13, 29.25 }\n"
        "J0.S1.species_end = { 550.02, 20.83 }\n"
        "J0.S1.rxn_end = { 320, 30 }\n"
        "J0.S1.b1 = { 364.9, 33.93 }\n"
        "J0.S1.b2 = { 350, 35 }\n"
        "J0.S2.species_end = { 99.98, 52.67 }\n"
        "J0.S2.rxn_end = { 330, 20 }\n"
        "J0.S2.b1 = { 285.1, 39.57 }\n"
        "J0.S2.b2 = { 290, 40 }\n";

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S1") == 560);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S1") == 0.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S2") == 30.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S2") == 37.5);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "J0") == 318.13);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "J0") == 29.25);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointX(doc, "J0", 0, 0, 0) == 550.02);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointY(doc, "J0", 0, 0, 0) == 20.83);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointX(doc, "J0", 0, 0, 0) == 320);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointY(doc, "J0", 0, 0, 0) == 30);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1X(doc, "J0", 0, 0, 0) == 364.9);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1Y(doc, "J0", 0, 0, 0) == 33.93);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2X(doc, "J0", 0, 0, 0) == 350);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2Y(doc, "J0", 0, 0, 0) == 35);

    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointX(doc, "J0", 0, 1, 0) == 99.98);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointY(doc, "J0", 0, 1, 0) == 52.67);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointX(doc, "J0", 0, 1, 0) == 330);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointY(doc, "J0", 0, 1, 0) == 20);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1X(doc, "J0", 0, 1, 0) == 285.1);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1Y(doc, "J0", 0, 1, 0) == 39.57);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2X(doc, "J0", 0, 1, 0) == 290);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2Y(doc, "J0", 0, 1, 0) == 40);

    delete doc;
}
END_TEST


START_TEST(test_control_points_unset)
{
    string model =
        "J0: S1->S2;\n"
        "S1.position = { 560, 0 }\n"
        "S2.position = { 30, 37.5 }\n"
        "J0.position = { 318.13, 29.25 }\n";

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S1") == 560);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S1") == 0.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S2") == 30.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S2") == 37.5);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "J0") == 318.13);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "J0") == 29.25);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointX(doc, "J0", 0, 0, 0) != 0.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointY(doc, "J0", 0, 0, 0) != 0.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointX(doc, "J0", 0, 0, 0) == 318.13 + 10);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointY(doc, "J0", 0, 0, 0) == 29.25 + 10);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1X(doc, "J0", 0, 0, 0) != 0.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1Y(doc, "J0", 0, 0, 0) != 0.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2X(doc, "J0", 0, 0, 0) != 0.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2Y(doc, "J0", 0, 0, 0) != 0.0);

    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointX(doc, "J0", 0, 1, 0) != 0.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointY(doc, "J0", 0, 1, 0) != 0.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointX(doc, "J0", 0, 1, 0) == 318.13 + 10);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointY(doc, "J0", 0, 1, 0) == 29.25 + 10);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1X(doc, "J0", 0, 1, 0) != 0.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1Y(doc, "J0", 0, 1, 0) != 0.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2X(doc, "J0", 0, 1, 0) != 0.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2Y(doc, "J0", 0, 1, 0) != 0.0);

    delete doc;
}
END_TEST


START_TEST(test_control_points_double_arcs)
{
    string model =
        "J0: 2 S1->S2;\n"
        "S1.position = { 560, 0 }\n"
        "S2.position = { 30, 37.5 }\n"
        "J0.position = { 318.13, 29.25 }\n"
        "J0.S1.species_end = { 550.02, 20.83 }\n"
        "J0.S1.b1 = { 364.9, 33.93 }\n"
        "J0.S1.b2 = { 350, 35 }\n"
        "J0.S1.arc2.species_end = { 550.01, 18.38 }\n"
        "J0.S1.arc2.b1 = { 342.95, 26.25 }\n"
        "J0.S1.arc2.b2 = { 490.02, 18.95 }\n"
        "J0.S2.species_end = { 99.98, 52.67 }\n"
        "J0.S2.b1 = { 285.1, 39.57 }\n"
        "J0.S2.b2 = { 290, 40 }\n";

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S1") == 560);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S1") == 0.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S2") == 30.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S2") == 37.5);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "J0") == 318.13);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "J0") == 29.25);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointX(doc, "J0", 0, 0, 0) == 550.02);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointY(doc, "J0", 0, 0, 0) == 20.83);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointX(doc, "J0", 0, 0, 0) == 318.13 + 10);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointY(doc, "J0", 0, 0, 0) == 29.25 + 10);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1X(doc, "J0", 0, 0, 0) == 364.9);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1Y(doc, "J0", 0, 0, 0) == 33.93);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2X(doc, "J0", 0, 0, 0) == 350);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2Y(doc, "J0", 0, 0, 0) == 35);

    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointX(doc, "J0", 0, 1, 0) == 550.01);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointY(doc, "J0", 0, 1, 0) == 18.38);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointX(doc, "J0", 0, 1, 0) == 318.13 + 10);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointY(doc, "J0", 0, 1, 0) == 29.25 + 10);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1X(doc, "J0", 0, 1, 0) == 342.95);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1Y(doc, "J0", 0, 1, 0) == 26.25);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2X(doc, "J0", 0, 1, 0) == 490.02);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2Y(doc, "J0", 0, 1, 0) == 18.95);

    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointX(doc, "J0", 0, 2, 0) == 99.98);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointY(doc, "J0", 0, 2, 0) == 52.67);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointX(doc, "J0", 0, 2, 0) == 318.13 + 10);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointY(doc, "J0", 0, 2, 0) == 29.25 + 10);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1X(doc, "J0", 0, 2, 0) == 285.1);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1Y(doc, "J0", 0, 2, 0) == 39.57);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2X(doc, "J0", 0, 2, 0) == 290);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2Y(doc, "J0", 0, 2, 0) == 40);

    delete doc;
}
END_TEST


START_TEST(test_control_points_second_arc_unset)
{
    string model =
        "J0: 2 S1->S2;\n"
        "S1.position = { 560, 0 }\n"
        "S2.position = { 30, 37.5 }\n"
        "J0.position = { 318.13, 29.25 }\n"
        "J0.S1.species_end = { 550.02, 20.83 }\n"
        "J0.S1.b1 = { 364.9, 33.93 }\n"
        "J0.S1.b2 = { 350, 35 }\n"
        "J0.S2.species_end = { 99.98, 52.67 }\n"
        "J0.S2.b1 = { 285.1, 39.57 }\n"
        "J0.S2.b2 = { 290, 40 }\n";

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S1") == 560);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S1") == 0.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S2") == 30.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S2") == 37.5);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "J0") == 318.13);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "J0") == 29.25);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointX(doc, "J0", 0, 0, 0) == 550.02);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointY(doc, "J0", 0, 0, 0) == 20.83);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointX(doc, "J0", 0, 0, 0) == 318.13 + 10);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointY(doc, "J0", 0, 0, 0) == 29.25 + 10);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1X(doc, "J0", 0, 0, 0) == 364.9);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1Y(doc, "J0", 0, 0, 0) == 33.93);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2X(doc, "J0", 0, 0, 0) == 350);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2Y(doc, "J0", 0, 0, 0) == 35);

    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointX(doc, "J0", 0, 1, 0) != 0.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointY(doc, "J0", 0, 1, 0) != 0.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointX(doc, "J0", 0, 1, 0) == 318.13 + 10);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointY(doc, "J0", 0, 1, 0) == 29.25 + 10);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1X(doc, "J0", 0, 1, 0) != 0.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1Y(doc, "J0", 0, 1, 0) != 0.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2X(doc, "J0", 0, 1, 0) != 0.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2Y(doc, "J0", 0, 1, 0) != 0.0);

    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointX(doc, "J0", 0, 2, 0) == 99.98);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointY(doc, "J0", 0, 2, 0) == 52.67);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointX(doc, "J0", 0, 2, 0) == 318.13 + 10);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointY(doc, "J0", 0, 2, 0) == 29.25 + 10);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1X(doc, "J0", 0, 2, 0) == 285.1);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1Y(doc, "J0", 0, 2, 0) == 39.57);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2X(doc, "J0", 0, 2, 0) == 290);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2Y(doc, "J0", 0, 2, 0) == 40);

    delete doc;
}
END_TEST


START_TEST(test_multi_segments)
{
  string model =
    "J0: S1->;\n"
    "S1.position = { 560, 0 }\n"
    "J0.position = { 318.13, 29.25 }\n"
    "J0.S1.seg1.species_end = { 550.02, 20.83 }\n"
    "J0.S1.seg1.b1 = { 364.9, 33.93 }\n"
    "J0.S1.seg1.b2 = { 350, 35 }\n"
    "J0.S1.seg1.rxn_end = { 400, 25 }\n"
    "J0.S1.seg2.species_end = { 400.5, 25.5 }\n"
    "J0.S1.seg2.b1 = { 265.1, 29.57 }\n"
    "J0.S1.seg2.b2 = { 280, 30 }\n";
    "J0.S1.seg2.rxn_end = { 328.13, 39.25 }\n";

  libsbml::SBMLDocument* doc = translateAntimony(model);
  fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S1") == 560);
  fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S1") == 0.0);
  fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "J0") == 318.13);
  fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "J0") == 29.25);
  fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointX(doc, "J0", 0, 0, 0) == 550.02);
  fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointY(doc, "J0", 0, 0, 0) == 20.83);
  fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1X(doc, "J0", 0, 0, 0) == 364.9);
  fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1Y(doc, "J0", 0, 0, 0) == 33.93);
  fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2X(doc, "J0", 0, 0, 0) == 350);
  fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2Y(doc, "J0", 0, 0, 0) == 35);
  fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointX(doc, "J0", 0, 0, 0) == 400);
  fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointY(doc, "J0", 0, 0, 0) == 25);

  fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointX(doc, "J0", 0, 0, 1) == 400.5);
  fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointY(doc, "J0", 0, 0, 1) == 25.5);
  fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1X(doc, "J0", 0, 0, 1) == 265.1);
  fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1Y(doc, "J0", 0, 0, 1) == 29.57);
  fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2X(doc, "J0", 0, 0, 1) == 280);
  fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2Y(doc, "J0", 0, 0, 1) == 30);
  fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointX(doc, "J0", 0, 0, 1) == 318.13 + 10);
  fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointY(doc, "J0", 0, 0, 1) == 29.25 + 10);

  delete doc;
}
END_TEST



START_TEST(test_export_auto_aliased_nodes)
{
    string model =
        "J0: S1->S2 + S3; ;\n"
        "J1: S2 + S1->S0; ;\n"
        "J2: S2->S3 + S1; ;\n"
        "J3: S1 + S2->S3 + S0; ;\n"
        "J4: S2 + S0 -> 2 S1;\n"
        "model.layout = on";

    libsbml::SBMLDocument* doc = translateAntimony(model);

    int nS1s = LIBSBMLNETWORK_CPP_NAMESPACE::getNumGraphicalObjects(doc, "S1");
    int nS2s = LIBSBMLNETWORK_CPP_NAMESPACE::getNumGraphicalObjects(doc, "S2");
    int nS3s = LIBSBMLNETWORK_CPP_NAMESPACE::getNumGraphicalObjects(doc, "S3");
    fail_unless(nS1s == 2);
    fail_unless(nS2s == 2);
    fail_unless(nS3s == 1);

    string rt = translateAntimonyFromDoc(doc);
    libsbml::SBMLDocument* doc2 = translateAntimony(rt);

    vector<string> ids = { "S1", "S2" };
    for (int s = 0; s < 2; s++) {
        string id = ids[s];
        for (int alias = 0; alias < 2; alias++) {
            string glyphId = LIBSBMLNETWORK_CPP_NAMESPACE::getId(doc, 0, id, alias);
            fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, glyphId) == LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc2, glyphId));
            fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, glyphId) == LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc2, glyphId));
        }
    }
    
    delete doc;
    delete doc2;
}
END_TEST


START_TEST(test_export_explicit_aliased_nodes)
{
    string model =
        "J0: S1->S2;\n"
        "J1: S1->S3; \n"
        "J2: S1->S4; \n"
        "S1.color.J2 = red\n"
        "";

    libsbml::SBMLDocument* doc = translateAntimony(model);

    int nS1s = LIBSBMLNETWORK_CPP_NAMESPACE::getNumGraphicalObjects(doc, "S1");
    int nS2s = LIBSBMLNETWORK_CPP_NAMESPACE::getNumGraphicalObjects(doc, "S2");
    fail_unless(nS1s == 2);
    fail_unless(nS2s == 1);

    string rt = translateAntimonyFromDoc(doc);
    libsbml::SBMLDocument* doc2 = translateAntimony(rt);

    string id = "S1";
    for (int alias = 0; alias < 2; alias++) {
        string glyphId = LIBSBMLNETWORK_CPP_NAMESPACE::getId(doc, 0, id, alias);
        fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, glyphId) == LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc2, glyphId));
        fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, glyphId) == LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc2, glyphId));
        if (alias == 1) {
            fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getFillColor(doc, glyphId) == "red");
        }
    }

    delete doc;
    delete doc2;
}
END_TEST



Suite *
create_suite_LayoutRender(void)
{
  Suite *suite = suite_create("Antimony LayoutRender");
  TCase *tcase = tcase_create("Antimony LayoutRender");


  tcase_add_test( tcase, test_basic_autolayout);
  tcase_add_test( tcase, test_basic_positions);
  tcase_add_test( tcase, test_basic_sizes);
  tcase_add_test( tcase, test_maxEdges);
  tcase_add_test( tcase, test_setLayoutStyle);
  tcase_add_test( tcase, test_layout_size);
  tcase_add_test( tcase, test_align_top);
  tcase_add_test( tcase, test_align_bottom);
  tcase_add_test( tcase, test_align_hCenter);
  tcase_add_test( tcase, test_align_right);
  tcase_add_test( tcase, test_align_left);
  tcase_add_test( tcase, test_align_vCenter);
  tcase_add_test( tcase, test_whole_model_settings);
  tcase_add_test( tcase, test_species_settings);
  tcase_add_test( tcase, test_compartment_settings);
  tcase_add_test( tcase, test_reaction_settings);
  tcase_add_test( tcase, test_locations_pos);
  tcase_add_test( tcase, test_locations_xy);
  tcase_add_test( tcase, test_individual_render);
  tcase_add_test( tcase, test_control_points);
  tcase_add_test( tcase, test_control_points_off_reaction);
  tcase_add_test( tcase, test_control_points_unset);
  tcase_add_test( tcase, test_control_points_double_arcs);
  tcase_add_test( tcase, test_control_points_second_arc_unset);
  tcase_add_test( tcase, test_multi_segments);
  tcase_add_test( tcase, test_export_auto_aliased_nodes);
  tcase_add_test( tcase, test_export_explicit_aliased_nodes);

  //tcase_add_test( tcase, test_compartment_settings);
  //tcase_add_test( tcase, test_compartment_settings);
  //tcase_add_test( tcase, test_compartment_settings);
  //tcase_add_test( tcase, test_useNameAsTextLabel);

  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS


