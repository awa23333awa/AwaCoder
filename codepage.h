#ifndef CODEPAGE_H
#define CODEPAGE_H

#include "codeeditor.h"
#include "modifiablepage.h"
#include "pagebrowser.h"

#include <QRegularExpression>

class LineIndexBar;

class CodePage : public CodeEditor, public ModifiablePage
{
    Q_OBJECT
private:
    explicit CodePage(PageBrowser* parent=nullptr);
    ~CodePage();
public:
    static const QRegularExpression cppFilePostfix;

    State state();

    static CodePage* newPage(PageBrowser* parent=nullptr);
    static CodePage* openFile(QString filePath,PageBrowser* parent=nullptr);

    // AbstractPage interface
public:
    QString getTitle();
    CodeEditor* getWidget();

    // ModifiablePage interface
public:
    bool save();
    void close();

signals:
    void fileSaved();
    void stateChanged(ModifiablePage::State);

private:
    QString filePath_;
    State state_;
};


#endif // CODEPAGE_H
