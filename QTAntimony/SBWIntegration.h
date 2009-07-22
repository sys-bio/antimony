#ifndef SBWINTEGRATION_H
#define SBWINTEGRATION_H

#ifdef SBW_INTEGRATION

#include "SBW/SBW.h"
#include "SBW/SBWC.h"
#include <QEvent>
#include <string>

// we need an event to be sent to the application that a new
//SBML model should be loaded

class QSBMLEvent : public QEvent
{
private:
    std::string m_sbmlContent;
public:
    QSBMLEvent(std::string sbmlContent);
    std::string getSBML();
};

// QT Antimony SBW Service ... just load an SBML file, send it to the application .. thats it
class SBWAntimony : SystemsBiologyWorkbench::SBWListener
{
public:
    SBWAntimony() {};
    virtual void onShutdown();
    static void registerMethods(MethodTable<SBWAntimony> &table);
    DataBlockWriter doAnalysisImpl(Module /*from*/, DataBlockReader arguments);
};

#endif



#endif // SBWINTEGRATION_H
