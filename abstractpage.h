#ifndef ABSTRACTPAGE_H
#define ABSTRACTPAGE_H

#include <QWidget>
#include <QTextDocument>

class PageBrowser;

class AbstractPage
{
public:
    enum struct State{
        NoState,Opened,Unsaved,Saved,New
    };

    virtual ~AbstractPage()=0;
    virtual QString getTitle()=0;
    virtual QWidget* getWidget()=0;
    virtual void close()=0;
    PageBrowser* pageBrowser();

};

#endif // ABSTRACTPAGE_H
