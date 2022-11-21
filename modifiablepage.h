#ifndef MODIFIABLEPAGE_H
#define MODIFIABLEPAGE_H

#include <abstractpage.h>

class ModifiablePage : public AbstractPage
{
public:
    ~ModifiablePage()=0;
    virtual bool save()=0;
    enum struct State{NoState,New,NewButEdited,Opened,Unsaved,Saved};
};

#endif // MODIFIABLEPAGE_H
