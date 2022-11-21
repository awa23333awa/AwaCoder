#include "pagebrowser.h"

#include "debug.h"

PageBrowser::PageBrowser(QWidget *parent)
    :QTabWidget(parent)
{
    setMovable(true);
    setTabsClosable(true);
    setUsesScrollButtons(true);
    connect(this,&PageBrowser::tabCloseRequested,this,&PageBrowser::removePage);
    connect(this,&PageBrowser::currentChanged,this,&PageBrowser::titleUpdated);
}

int PageBrowser::addPage(AbstractPage *page)
{
    int result=addTab(page->getWidget(),page->getTitle());
    setCurrentIndex(result);
    return result;
}

int PageBrowser::addPage(AbstractPage *page, const QString &label)
{
    int result=addTab(page->getWidget(),label);
    setCurrentIndex(result);
    return result;
}

int PageBrowser::addPage(AbstractPage *page, const QIcon &icon, const QString &label)
{
    int result=addTab(page->getWidget(),icon,label);
    setCurrentIndex(result);
    return result;
}

AbstractPage *PageBrowser::getPage(int index)
{
    return dynamic_cast<AbstractPage*>(widget(index));
}

void PageBrowser::removePage(int index)
{
    auto page=getPage(index);
    page->close();
    removeTab(index);
    delete page;
}

AbstractPage *PageBrowser::currentPage()
{
    return dynamic_cast<AbstractPage*>(currentWidget());
}

AbstractPage *PageBrowser::page(int index)
{
    return dynamic_cast<AbstractPage*>(widget(index));
}

void PageBrowser::updateTitle()
{
    setTabText(currentIndex(),currentPage()->getTitle());
    emit titleUpdated();
}
