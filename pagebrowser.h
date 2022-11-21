#ifndef PAGEBROWSER_H
#define PAGEBROWSER_H

#include <QTabWidget>
#include "abstractpage.h"

class PageBrowser : public QTabWidget
{
    Q_OBJECT
public:
    explicit PageBrowser(QWidget* parent=nullptr);

    virtual int addPage(AbstractPage* page);
    virtual int addPage(AbstractPage* page,const QString& label);
    virtual int addPage(AbstractPage* page,const QIcon& icon,const QString& label);
    virtual AbstractPage* getPage(int index);
    virtual void removePage(int index);
    virtual AbstractPage* currentPage();
    virtual AbstractPage* page(int index);
    virtual void updateTitle();

signals:
    void titleUpdated();
};

#endif // PAGEBROWSER_H
