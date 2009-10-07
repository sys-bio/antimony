#include "SBWIntegration.h"

#ifdef SBW_INTEGRATION

#include "SBW/SBWC.h"
#include <QEvent>
#include <QApplication>


// we need an event to be sent to the application that a new
//SBML model should be loaded

QSBMLEvent::QSBMLEvent(QString sbmlContent)
    :  QEvent(QEvent::User),
    m_sbmlContent(sbmlContent)
{
}

QString QSBMLEvent::getSBML()
{
    return m_sbmlContent;
}

#endif

