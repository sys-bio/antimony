#ifndef SBWINTEGRATION_H
#define SBWINTEGRATION_H

#ifdef SBW_INTEGRATION
#include <QEvent>
#include <QString>

#include "SBW/SBWC.h"

// we need an event to be sent to the application that a new
//SBML model should be loaded
class QSBMLEvent : public QEvent
{
private:
    QString m_sbmlContent;
public:
    QSBMLEvent(QString sbmlContent);
    QString getSBML();
};

#endif



#endif // SBWINTEGRATION_H
