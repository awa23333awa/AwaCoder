#include "awacoder.h"
#include "mainwindow.h"

#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    AwaCoder a(argc, argv);
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "AwaCoder_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.setWindowIcon(QIcon{":/img/icon"});
    w.setMinimumSize(800,600);
    w.show();
    return a.exec();
}
