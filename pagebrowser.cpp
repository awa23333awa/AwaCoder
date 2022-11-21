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

int PageBrowser::addPage(Page *page)
{
    page->pageBrowser_=this;
    auto index=indexOf(page);
    if(index!=-1){
        setCurrentIndex(index);
        return index;
    }
    int result=addTab(page,page->getTitle());
    connect(page,&Page::titleChanged,this,&PageBrowser::updateTitle);
    setCurrentIndex(result);
    return result;
}


Page *PageBrowser::getPage(int index)
{
    return dynamic_cast<Page*>(widget(index));
}

void PageBrowser::removePage(int index)
{
    auto page=getPage(index);
    disconnect(page,&Page::titleChanged,this,&PageBrowser::updateTitle);
    page->pageBrowser_=nullptr;
    page->close();
    removeTab(index);
}

Page *PageBrowser::currentPage()
{
    return dynamic_cast<Page*>(currentWidget());
}

Page *PageBrowser::page(int index)
{
    return dynamic_cast<Page*>(widget(index));
}

void PageBrowser::updateTitle()
{
    setTabText(currentIndex(),currentPage()->getTitle());
    emit titleUpdated();
}
