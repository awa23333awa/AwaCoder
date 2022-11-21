#ifndef SETTINGSCONFIG_H
#define SETTINGSCONFIG_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QVariant>

class SettingsConfig : public QObject
{
    Q_OBJECT
public:

    explicit SettingsConfig(QObject *parent = nullptr);

};

#endif // SETTINGSCONFIG_H
