#include "Tutorial.h"

Tutorial::Tutorial(QWidget* parent)
        :QTextBrowser(parent)
{
    setOpenLinks(false);
#include "Tutorial.xxd"
    // created using 'xxd -i Tutorial.html > Tutorial.xxd' then changing the
    // main bit to 'static const char' and the _len to
    // 'static const unsigned int'
    std::string tutorial_string;
    tutorial_string.assign(Tutorial_html, Tutorial_html_len);
    setHtml(tutorial_string.c_str());
}
