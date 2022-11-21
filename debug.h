#ifndef DEBUG_H
#define DEBUG_H

#include <QDebug>

#define dbg do{qDebug()<<"Line "<<__LINE__<<" at "<<__FILE__;}while(0)

#endif // DEBUG_H
