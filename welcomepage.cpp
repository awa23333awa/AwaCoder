#include "welcomepage.h"

#include <QLabel>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QFont>

#include "debug.h"

WelcomePage::WelcomePage(QWidget *parent)
    : QWidget{parent}
{
    auto theLayout=new QVBoxLayout{};
    auto title=new QLabel(tr("Welcome"));
    auto content=new QTextBrowser{};

    auto theFont=title->font();
    theFont.setPixelSize(32);
    title->setFont(theFont);
    content->setText(tr("Thank you for testing but I am sorry I can provide you anything"));
    theLayout->addWidget(title);
    theLayout->addSpacing(fontMetrics().height()/2);
    theLayout->addWidget(content);

    setLayout(theLayout);
}

QString WelcomePage::getTitle()
{
    return tr("Welcome");
}

QWidget *WelcomePage::getWidget()
{
    return this;
}

void WelcomePage::close()
{

}
