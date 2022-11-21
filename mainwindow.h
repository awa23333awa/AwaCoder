#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pagebrowser.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void newFile();
    void openFile();
    void saveFile();
    void closeFile();
    void updateTitle();

    void welcome();
    void options();
    void plugins();

private:
    PageBrowser* pageBrower;
};
#endif // MAINWINDOW_H
