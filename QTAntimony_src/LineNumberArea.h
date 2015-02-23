#ifndef LINENUMBERAREA_H
#define LINENUMBERAREA_H

#include <QWidget>

class QFile;
class ChangeableTextBox;

class LineNumberArea : public QWidget
 {
 public:
     LineNumberArea(ChangeableTextBox *editor);
     QSize sizeHint() const;

 protected:
     void paintEvent(QPaintEvent *event);

 private:
     ChangeableTextBox *m_codeEditor;
 };

#endif // LINENUMBERAREA_H
