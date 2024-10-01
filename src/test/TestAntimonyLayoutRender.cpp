/**
 * \file    TestAntimonyLayoutRender.c
 * \brief   Test Antimony's Layout and Render constructs.
 * \author  Lucian Smith
 * ---------------------------------------------------------------------- -->*/

#include "libutil.h"
#include "antimony_api.h"
#include "registry.h"
#include <sbml/SBMLTypes.h>
#include "libsbmlnetwork_layout_helpers.h"
#include "libsbmlnetwork_sbmldocument.h"
#include "libsbmlnetwork_sbmldocument_layout.h"
#include "libsbmlnetwork_sbmldocument_render.h"


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

START_TEST(test_useNameAsTextLabel)
{
    string model =
        "S1->S2;\n"
        "S1 is \"Species 1\"\n"
        "model.autolayout.useNameAsTextLabel = false\n"
        ;

    libsbml::SBMLDocument* doc = translateAntimony(model);
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getText(doc, "S1") == "S1");
    delete doc;

    string model2 =
        "S1->S2;\n"
        "S1 is \"Species 1\"\n"
        "model.layout = on\n"
        ;

    doc = translateAntimony(model2);
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getText(doc, "S1") == "Species 1");
    delete doc;
}
END_TEST

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
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentStrokeColor(doc) == "mandy");
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
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingStrokeColor(doc) == "gondola");
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingStrokeWidth(doc) == 3.0);
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingFillColor(doc) == "gondola");

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
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionWidth(doc) == 1234.0);
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionHeight(doc) == 1432.0);
    delete doc;

    model =
        "S1->S2;\n"
        "model.layout.width = 1234\n"
        "model.layout.height = 1432\n"
        ;

    doc = translateAntimony(model);
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionWidth(doc) == 1234.0);
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionHeight(doc) == 1432.0);
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
        "model.layout.align_top = {S1, S2, S3}\n"
        ;

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S1") == LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S2"));
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S2") == LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S3"));
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S1") > 700);
    delete doc;
}
END_TEST

START_TEST(test_align_align_hCenter)
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
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S1") > 400);
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(doc, "S1") < 600);
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
        "model.layout.align_right = {S1, S2, S3}\n"
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
        "model.layout.align_right = {S1, S2, S3}\n"
        ;

    libsbml::SBMLDocument* doc = translateAntimony(model);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S1") == LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S2"));
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S2") == LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S3"));
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S1") > 400);
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(doc, "S1") < 600);
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
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentStrokeColor(doc) == "azure");
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesStrokeColor(doc) == "azure");
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getReactionStrokeColor(doc) == "azure");
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
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFontWeight(doc) == "normal");
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
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesStrokeColor(doc) == "azure");
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
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionWidth(doc, "C") == 420.0);
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionHeight(doc, "C") == 550.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFillColor(doc) == "khaki");
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentStrokeColor(doc) == "azure");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFontColor(doc) == "coral");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentStrokeWidth(doc) == 32.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFontFamily(doc) == "monospace");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFontSizeAsDouble(doc) == 4.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFontStyle(doc) == "italic");
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFontWeight(doc) == "normal");
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
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionWidth(doc, "J0") == 420.0);
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionHeight(doc, "J0") == 550.0);
    fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getReactionFillColor(doc) == "khaki");
    //fail_unless(LIBSBMLNETWORK_CPP_NAMESPACE::getReactionStrokeColor(doc) == "azure");
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





Suite *
create_suite_LayoutRender(void)
{
  Suite *suite = suite_create("Antimony LayoutRender");
  TCase *tcase = tcase_create("Antimony LayoutRender");


  tcase_add_test( tcase, test_useNameAsTextLabel);
  tcase_add_test( tcase, test_basic_autolayout);
  tcase_add_test( tcase, test_basic_positions);
  tcase_add_test( tcase, test_basic_sizes);
  tcase_add_test( tcase, test_maxEdges);
  tcase_add_test( tcase, test_setLayoutStyle);
  tcase_add_test( tcase, test_layout_size);
  tcase_add_test( tcase, test_align_top);
  tcase_add_test( tcase, test_align_bottom);
  tcase_add_test( tcase, test_align_align_hCenter);
  tcase_add_test( tcase, test_align_right);
  tcase_add_test( tcase, test_align_left);
  tcase_add_test( tcase, test_align_vCenter);
  tcase_add_test( tcase, test_whole_model_settings);
  tcase_add_test( tcase, test_species_settings);
  tcase_add_test( tcase, test_compartment_settings);
  tcase_add_test( tcase, test_reaction_settings);
  tcase_add_test( tcase, test_locations_pos);
  tcase_add_test( tcase, test_locations_xy);
  //tcase_add_test( tcase, test_compartment_settings);
  //tcase_add_test( tcase, test_compartment_settings);
  //tcase_add_test( tcase, test_compartment_settings);
  //tcase_add_test( tcase, test_compartment_settings);
  //tcase_add_test( tcase, test_compartment_settings);
  //tcase_add_test( tcase, test_compartment_settings);
  //tcase_add_test( tcase, test_compartment_settings);
  //tcase_add_test( tcase, test_compartment_settings);

  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS


