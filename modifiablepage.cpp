#include "modifiablepage.h"

#include <QMessageBox>

ModifiablePage::ModifiablePage(QWidget *parent)
    :Page{parent},
     state_{State::NoState}
{

}

ModifiablePage::State ModifiablePage::state()
{
    return state_;
}

bool ModifiablePage::save()
{
    return true;
}

void ModifiablePage::close()
{
    if(state_==State::NewButEdited||state_==State::Unsaved){
        auto btn=QMessageBox::information(this,tr("Didn't save"),tr("You didn't save. Do you want to save?"),QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
        if(btn==QMessageBox::Yes){
            while(!save()&&btn==QMessageBox::Yes){
                btn=QMessageBox::information(this,tr("Failed to save"),tr("Retry or not?"),QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
            }
        }
    }
}
