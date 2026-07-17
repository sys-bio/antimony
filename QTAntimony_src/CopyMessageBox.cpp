#include "CopyMessageBox.h"
#include "QTAntimony.h"

CopyMessageBox::CopyMessageBox(QWidget* parent)
  : QMessageBox(parent)
{
  setStyleSheet("QMessageBox { messagebox-text-interaction-flags: 1 }");
  QTAntimony::ApplyWindowIcon(this);
}
