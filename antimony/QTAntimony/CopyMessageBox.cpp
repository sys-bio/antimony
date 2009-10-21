#include "CopyMessageBox.h"

CopyMessageBox::CopyMessageBox(QWidget* parent)
  : QMessageBox(parent)
{
  setStyleSheet("QMessageBox { messagebox-text-interaction-flags: 1 }");
}
