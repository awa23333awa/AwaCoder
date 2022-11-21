#ifndef PAGE_H
#define PAGE_H

#include <QWidget>
#include <QTextDocument>

class PageBrowser;

class Page:public QWidget
{
    Q_OBJECT
public:
    explicit Page(QWidget* parent);
    virtual ~Page();
    virtual QString getTitle();
    virtual void close();
    PageBrowser* pageBrowser()const;

signals:
    void titleChanged();

protected:
    QString title_;
    friend class PageBrowser;
    PageBrowser* pageBrowser_{nullptr};
};

#endif // PAGE_H
