#ifndef MODIFIABLEPAGE_H
#define MODIFIABLEPAGE_H

#include "page.h"

class ModifiablePage : public Page
{
    Q_OBJECT
public:
    enum struct State{NoState,New,NewButEdited,Opened,Unsaved,Saved};

    ModifiablePage(QWidget* parent=nullptr);

    State state();
    virtual bool save();
protected:
    State state_;

signals:
    void justSaved();
    void stateChanged(State);

    // Page interface
public:
    void close();
};

#endif // MODIFIABLEPAGE_H
