#include "page.h"
#include "pagebrowser.h"


Page::Page(QWidget *parent)
    :QWidget{parent},
     title_{tr("Page")}
{

}

Page::~Page()
{
    
}

QString Page::getTitle()
{
    return title_;
}

void Page::close()
{

}

PageBrowser *Page::pageBrowser() const
{
    return pageBrowser_;
}
