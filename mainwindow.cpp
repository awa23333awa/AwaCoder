#include "mainwindow.h"
#include "codepage.h"
#include "welcomepage.h"
//#include "settingspage.h"

#include <QMenuBar>
#include <QAction>
#include <QKeySequence>
#include <QFile>
#include <QInputDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QTabBar>
#include <QIcon>

#include "debug.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),pageBrower{new PageBrowser{this}}
{

    auto theMenuBar=menuBar();

    auto fileMenu=theMenuBar->addMenu(tr("&File"));
    fileMenu->addAction(tr("&New"),QKeySequence::New,this,&MainWindow::newFile);
    fileMenu->addAction(tr("&Open"),QKeySequence::Open,this,&MainWindow::openFile);
    fileMenu->addAction(tr("&Save"),QKeySequence::Save,this,&MainWindow::saveFile);
    fileMenu->addAction(tr("Close(&j)"),QKeySequence::Close,this,&MainWindow::closeFile);
    fileMenu->addAction(tr("&Quit"),QKeySequence::Quit,this,&MainWindow::close);

    auto editMenu=theMenuBar->addMenu(tr("&Edit"));

    auto toolMenu=theMenuBar->addMenu(tr("&Tool"));
    toolMenu->addAction(tr("&Options"),QKeySequence::Preferences,this,&MainWindow::options);
    toolMenu->addAction(tr("&Welcome"),this,&MainWindow::welcome);
    toolMenu->addAction(tr("&Plugins"),this,&MainWindow::plugins);

    auto helpMenu=theMenuBar->addMenu(tr("&Help"));
    helpMenu->addAction(tr("About Qt"),[this](){
        QMessageBox::aboutQt(this);
    });

    connect(pageBrower,&PageBrowser::titleUpdated,this,&MainWindow::updateTitle);

    welcome();

    setCentralWidget(pageBrower);
}

MainWindow::~MainWindow()
{
}

void MainWindow::newFile()
{
    auto codePage=CodePage::newPage(pageBrower);
    pageBrower->addPage(codePage,tr("New file"));
    updateTitle();
}

void MainWindow::openFile()
{
    auto filePath=QFileDialog::getOpenFileName(this,tr("Open a file"));
    if(filePath.isEmpty()){
        return;
    }
    auto codePage=CodePage::openFile(filePath,pageBrower);
    if(codePage){
        pageBrower->addPage(codePage,codePage->getTitle());
        updateTitle();
    }
}

void MainWindow::saveFile()
{
    auto currentPage=dynamic_cast<ModifiablePage*>(pageBrower->currentPage());
    if(currentPage->save()){
        updateTitle();
    }
}

void MainWindow::closeFile()
{
    auto page=pageBrower->currentIndex();
    pageBrower->removePage(page);
    updateTitle();
}

void MainWindow::updateTitle()
{
    QString title{tr("AwaCoder")};
    if(pageBrower->count()==0){
        title+=tr(" - Cake is a lie~");
    }else{
        title+=tr(" - ");
        title+=pageBrower->currentPage()->getTitle();
    }
    setWindowTitle(title);

}

void MainWindow::welcome()
{
    pageBrower->addPage(new WelcomePage{this},tr("Welcome"));
    updateTitle();
}

void MainWindow::options()
{
    QMessageBox::information(this,tr("Sorry"),tr("This function is developing."));
}

void MainWindow::plugins()
{
    QMessageBox::information(this,tr("Sorry"),tr("This function is developing."));
}


