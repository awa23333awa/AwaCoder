#include "codepage.h"
#include "highlighter.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QTextDocument>
#include <QTextCursor>
#include <QPainter>
#include <QTextBlock>
#include <QScrollBar>
#include <QCompleter>

#include "debug.h"

const QRegularExpression CodePage::cppFilePostfix{".*\\.(cpp|cxx|cc|C|h|hpp|hxx|inl|cppm)$"};

CodePage::CodePage(PageBrowser* parent)
    :CodeEditor(parent)
{
    setParent(parent);
    connect(this,&CodePage::fileSaved,[this](){
        state_=State::Saved;
        pageBrowser()->updateTitle();
    });
    connect(this,&CodePage::textChanged,[this](){
        if(state_!=State::New&&state_!=State::NewButEdited){
            state_=State::Unsaved;
            pageBrowser()->updateTitle();

        }else if(state_==State::New){
            state_=State::NewButEdited;
            pageBrowser()->updateTitle();
        }
    });
}

CodePage::~CodePage()
{

}

ModifiablePage::State CodePage::state()
{
    return state_;
}

CodePage* CodePage::newPage(PageBrowser* parent)
{
    auto page=new CodePage{parent};
    page->state_=State::New;
    return page;
}

CodePage *CodePage::openFile(QString filePath,PageBrowser* parent)
{
    if(filePath.isEmpty()){
        return nullptr;
    }
    QFile file{filePath};
    if(!file.open(QFile::ReadOnly)){
        return nullptr;
    }
    auto page=new CodePage{parent};
    page->filePath_=filePath;
    page->state_=State::Opened;
    page->setPlainText(file.readAll());
    page->state_=State::Opened;
    if(cppFilePostfix.match(filePath).hasMatch()){
        new Highlighter{page->document()};
    }
    return page;
}

QString CodePage::getTitle()
{
    if(state_==State::New){
        return tr("New file");
    }else if(state_==State::NewButEdited){
        return tr("New file *");
    }else if(state_==State::Unsaved){
        return QUrl{filePath_}.fileName()+" *";
    }else{
        return QUrl{filePath_}.fileName();
    }
}

CodeEditor* CodePage::getWidget()
{
    return this;
}

bool CodePage::save()
{
    if(state_==State::New||state_==State::NewButEdited){
        filePath_=QFileDialog::getSaveFileName(this,tr("Save as"));
        if(cppFilePostfix.match(filePath_).hasMatch()){
            new Highlighter{document()};
        }
    }
    if(filePath_.isEmpty()){
        return false;
    }
    QFile file{filePath_};
    if(!file.open(QFile::WriteOnly)){
        QMessageBox::critical(this,tr("Error"),tr("Failed to save"));
        return false;
    }
    file.write(toPlainText().toUtf8());
    state_=State::Saved;
    pageBrowser()->updateTitle();
    return true;
}

void CodePage::close()
{
    if(state_==State::NewButEdited||state_==State::Unsaved){
        auto btn=QMessageBox::information(this,tr("Didn't save"),tr("You didn't save the file. Do you want to save?"),QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
        if(btn==QMessageBox::Yes){
            while(!save()&&btn==QMessageBox::Yes){
                btn=QMessageBox::information(this,tr("Failed to save"),tr("Retry or not?"),QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
            }
        }
    }
}
