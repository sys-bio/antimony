#include "Tutorial.h"

Tutorial::Tutorial(QWidget* parent)
        :QTextBrowser(parent)
{
#include "Tutorial.xxd"
    std::string tutorial_string;
    tutorial_string.assign(Tutorial_html, Tutorial_html_len);
    setHtml(tutorial_string.c_str());
}
