#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>

class QSettings;
class PageBrowser;
class SettingsConfig;
class WelcomePage;
class SettingsPage;

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
    QSettings* settings_;
    SettingsConfig* settingsConfig_;
    PageBrowser* pageBrowser_;
    WelcomePage* welcomePage_;
    SettingsPage* settingsPage_;
};
#endif // MAINWINDOW_H
