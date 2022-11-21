#include "abstractpage.h"
#include "pagebrowser.h"


AbstractPage::~AbstractPage(){

}

PageBrowser *AbstractPage::pageBrowser()
{
    return qobject_cast<PageBrowser*>(dynamic_cast<QWidget*>(this)->parent()->parent());
}
