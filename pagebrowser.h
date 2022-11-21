#ifndef PAGEBROWSER_H
#define PAGEBROWSER_H

#include <QTabWidget>
#include "page.h"

class PageBrowser : public QTabWidget
{
    Q_OBJECT
public:
    explicit PageBrowser(QWidget* parent=nullptr);

    virtual int addPage(Page* page);
    virtual Page* getPage(int index);
    virtual void removePage(int index);
    virtual Page* currentPage();
    virtual Page* page(int index);
    virtual void updateTitle();

signals:
    void titleUpdated();
};

#endif // PAGEBROWSER_H
