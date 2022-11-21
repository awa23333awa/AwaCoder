#ifndef CODEPAGE_H
#define CODEPAGE_H

#include "modifiablepage.h"

class CodeEditor;

class CodePage : public ModifiablePage
{
    Q_OBJECT
public:
    explicit CodePage(QWidget* parent=nullptr);
    explicit CodePage(QString fileName,QWidget* parent=nullptr);
    ~CodePage();

    State state();

    // AbstractPage interface
public:
    QString getTitle();

    // ModifiablePage interface
public:
    bool save();

private:
    QString fileName_;
    CodeEditor* codeEditor_;
};


#endif // CODEPAGE_H
