This is enough of the QTFindReplaceDialog project, hosted at http://qtfindreplace.sourceforge.net/, to work for QTAntimony.  The license is left unchanged for this part of the source code.  The code was copied in January of 2015, though the project had not been updated at that point since 2012.

The main changes made to make this work include:
 * Changing the reference edit window to QTPlainTextEdit instead of QTTextEdit.
 * Making it work as included source, instead of as a library.
 * Making 'setTextEdit' into a slot.
 * Fixing https://sourceforge.net/p/qtfindreplace/bugs/1/

