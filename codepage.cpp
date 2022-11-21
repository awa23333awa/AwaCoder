#include "codepage.h"
#include "pagebrowser.h"
#include "codeeditor.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QTextDocument>
#include <QTextCursor>
#include <QPainter>
#include <QTextBlock>
#include <QScrollBar>
#include <QHBoxLayout>

#include "debug.h"


CodePage::CodePage(QWidget *parent)
    :ModifiablePage{parent},
     codeEditor_{new CodeEditor{this}}
{
    state_=State::New;
    connect(this,&CodePage::justSaved,[this](){
        state_=State::Saved;
        emit titleChanged();

    });
    connect(codeEditor_,&CodeEditor::textChanged,[this](){
        if(state_!=State::New&&state_!=State::NewButEdited){
            state_=State::Unsaved;
            emit titleChanged();

        }else if(state_==State::New){
            state_=State::NewButEdited;
            emit titleChanged();
        }
    });
    auto theLayout=new QHBoxLayout{};
    theLayout->addWidget(codeEditor_);
    theLayout->setContentsMargins(0,0,0,0);
    setLayout(theLayout);
}

CodePage::CodePage(QString fileName, QWidget *parent)
    :CodePage(parent)
{
    if(fileName.isEmpty()){
        return;
    }
    QFile file{fileName};
    if(!file.open(QFile::ReadOnly)){
        return;
    }
    fileName_=fileName;
    title_=QUrl{fileName_}.fileName();
    state_=State::Opened;
    codeEditor_->setPlainText(file.readAll());
    state_=State::Opened;
}

CodePage::~CodePage()
{

}

ModifiablePage::State CodePage::state()
{
    return state_;
}

QString CodePage::getTitle()
{
    if(state_==State::New){
        return tr("New file");
    }else if(state_==State::NewButEdited){
        return tr("New file *");
    }else if(state_==State::Unsaved){
        return title_+" *";
    }else{
        return title_;
    }
}

bool CodePage::save()
{
    if(state_==State::New||state_==State::NewButEdited){
        fileName_=QFileDialog::getSaveFileName(this,tr("Save as"));
        title_=QUrl{fileName_}.fileName();
    }
    if(fileName_.isEmpty()){
        return false;
    }
    QFile file{fileName_};
    if(!file.open(QFile::WriteOnly)){
        QMessageBox::critical(this,tr("Error"),tr("Failed to save"));
        return false;
    }
    file.write(codeEditor_->toPlainText().toUtf8());
    state_=State::Saved;
    emit titleChanged();
    return true;
}

