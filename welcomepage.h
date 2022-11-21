#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include "abstractpage.h"

#include <QWidget>

class WelcomePage : public QWidget, public AbstractPage
{
    Q_OBJECT
public:
    explicit WelcomePage(QWidget *parent = nullptr);

signals:


    // AbstractPage interface
public:
    QString getTitle();
    QWidget *getWidget();
    void close();
};

#endif // WELCOMEPAGE_H
