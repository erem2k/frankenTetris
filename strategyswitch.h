#ifndef STRATEGYSWITCH_H
#define STRATEGYSWITCH_H

#include <QObject>

#include "loadingwidget.h"
#include "menuwidget.h"
#include "gamewidget.h"
#include "highscorewidget.h"
#include "quitmenuwidget.h"

class strategySwitch : public QObject
{
    Q_OBJECT
private:
    QWidget* currentMode;
public:
    enum mode {
        Loading,
        MainMenu,
        Game,
        HighscoreMenu,
        QuitMenu
    };

    explicit strategySwitch(QObject *parent = 0);
    void executeMode();

signals:
    void newMode(int);
    void logEvent(QString);
public slots:
    void setMode(mode,QWidget*);
};

#endif // STRATEGYSWITCH_H
