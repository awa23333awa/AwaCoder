#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include "page.h"

#include <QWidget>

class WelcomePage :public Page
{
    Q_OBJECT
public:
    explicit WelcomePage(QWidget* parent=nullptr);

private:

signals:


    // AbstractPage interface
public:
    QString getTitle();
    void close();
};

#endif // WELCOMEPAGE_H
