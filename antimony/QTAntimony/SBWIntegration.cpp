#include "SBWIntegration.h"

#ifdef SBW_INTEGRATION

#include "SBW/SBW.h"
#include "SBW/SBWC.h"
#include <QEvent>
#include <QApplication>
#include <string>
#include <cstdlib>
using namespace std;
using namespace SystemsBiologyWorkbench;


// we need an event to be sent to the application that a new
//SBML model should be loaded

QSBMLEvent::QSBMLEvent(std::string sbmlContent)
    :  QEvent(QEvent::User),
    m_sbmlContent(sbmlContent)
{
}

string QSBMLEvent::getSBML()
{
    return m_sbmlContent;
}

void SBWAntimony::onShutdown()
{
    exit(0);
}

void SBWAntimony::registerMethods(MethodTable<SBWAntimony> &table)
{
    table.addMethod(&SBWAntimony::doAnalysisImpl,"void doAnalysis(string)",0,"");
}

DataBlockWriter SBWAntimony::doAnalysisImpl(Module /*from*/, DataBlockReader arguments)
{
    string sbml;
    arguments >> sbml;
    qApp->postEvent(qApp, new QSBMLEvent(sbml));
    return DataBlockWriter();
}

#endif

