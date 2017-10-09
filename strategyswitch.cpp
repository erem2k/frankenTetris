#include "strategyswitch.h"
#include <QWidget>

/*----------PUBLIC--------------*/
strategySwitch::strategySwitch(QObject *parent) : QObject(parent)
{
    currentMode=nullptr;

}

void strategySwitch::executeMode()
{
    if(!currentMode)
        return;
    this->connect(currentMode,SIGNAL(newModeRequest(int)),this,SIGNAL(newMode(int)));
    this->connect(this,SIGNAL(logEvent(QString)),&(tetrisLogger::Instance()),SLOT(logEvent(QString)));

    currentMode->show();
}

/*-----------SLOTS--------------*/
void strategySwitch::setMode(mode modeToSet, QWidget* parentWidget)
{
    if(currentMode)
        delete(currentMode);

    switch(modeToSet)
    {
        case mode::Loading:
            currentMode=new loadingWidget(parentWidget);
            break;
        case mode::MainMenu:
            currentMode=new menuWidget(parentWidget);
            break;
        case mode::Game:
            currentMode=new gameWidget(parentWidget);
            break;
        case mode::HighscoreMenu:
            currentMode=new highscoreWidget(parentWidget);
            break;
        case mode::QuitMenu:
            currentMode=new quitMenuWidget(parentWidget);
            break;
        default:
            currentMode=new menuWidget(parentWidget);
    }

    QString stringToLog("StrategySwitch: New Mode set - ");
    stringToLog.append(QString::number(int(modeToSet)));

    emit logEvent(stringToLog);
    this->executeMode();
}
