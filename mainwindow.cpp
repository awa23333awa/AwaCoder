#include "mainwindow.h"
#include "codepage.h"
#include "welcomepage.h"
#include "plugininterface.h"
#include "pagebrowser.h"
#include "codeeditor.h"

#include <QMenuBar>
#include <QAction>
#include <QKeySequence>
#include <QFile>
#include <QInputDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QTabBar>
#include <QIcon>
#include <QPluginLoader>
#include <QSettings>

#include "debug.h"

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent),
     settings_{new QSettings{this}},
     pageBrowser_{new PageBrowser{this}},
     welcomePage_{nullptr}
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

    connect(pageBrowser_,&PageBrowser::titleUpdated,this,&MainWindow::updateTitle);

    welcome();

    setCentralWidget(pageBrowser_);
}

MainWindow::~MainWindow()
{
}

void MainWindow::newFile()
{
    auto codePage=new CodePage{pageBrowser_};
    pageBrowser_->addPage(codePage);
    updateTitle();
}

void MainWindow::openFile()
{
    auto filePath=QFileDialog::getOpenFileName(this,tr("Open a file"));
    if(filePath.isEmpty()){
        return;
    }
    auto codePage=new CodePage{filePath,pageBrowser_};
    if(codePage){
        pageBrowser_->addPage(codePage);
        updateTitle();
    }
}

void MainWindow::saveFile()
{
    auto currentPage=dynamic_cast<ModifiablePage*>(pageBrowser_->currentPage());
    if(!currentPage){
        return;
    }
    if(currentPage->save()){
        updateTitle();
    }
}

void MainWindow::closeFile()
{
    auto page=pageBrowser_->currentIndex();
    pageBrowser_->removePage(page);
    updateTitle();
}

void MainWindow::updateTitle()
{
    QString title{tr("AwaCoder")};
    if(pageBrowser_->count()){
        title+=tr(" - ");
        title+=pageBrowser_->currentPage()->getTitle();
    }
    setWindowTitle(title);

}

void MainWindow::welcome()
{
    if(welcomePage_==nullptr){
        welcomePage_=new WelcomePage{pageBrowser_};
    }
    pageBrowser_->addPage(welcomePage_);
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


