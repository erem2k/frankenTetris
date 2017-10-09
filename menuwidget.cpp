#include "menuwidget.h"

menuWidget::menuWidget(QWidget *parent): QWidget(parent)
{
    this->currentOption=0;

    this->setGeometry(0,367,512,145);
    this->setFocus();

    this->uiBar=new QLabel(this);
    this->menuText=new QLabel(this);
    this->playSelect=new QLabel(this);
    this->scoreSelect=new QLabel(this);
    this->quitSelect=new QLabel(this);

    this->uiBar->setGeometry(0,0,512,145);
    this->menuText->setGeometry(47,60,421,62);
    this->playSelect->setGeometry(23,58,144,31);
    this->scoreSelect->setGeometry(157,58,200,31);
    this->quitSelect->setGeometry(347,58,145,31);

    this->uiBar->setPixmap(QPixmap(":/images/resources/UIBar.png"));
    this->menuText->setPixmap(QPixmap(":/images/resources/mainMenu/menuText.png"));
    this->playSelect->setPixmap(QPixmap(":/images/resources/mainMenu/selectPlay.png"));
    this->scoreSelect->setPixmap(QPixmap(":/images/resources/mainMenu/selectScores.png"));
    this->quitSelect->setPixmap(QPixmap(":/images/resources/mainMenu/selectQuit.png"));

    this->scoreSelect->hide();
    this->quitSelect->hide();

    connect(this,SIGNAL(logEvent(QString)),&(tetrisLogger::Instance()),SLOT(logEvent(QString)));
}

void menuWidget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Right:
            if(currentOption!=2)
                currentOption++;
        break;
        case Qt::Key_Left:
            if(currentOption!=0)
                currentOption--;
        break;
        case Qt::Key_Space:
            QString loggedEvent("Main Menu: Mode ");
            loggedEvent.append(QString::number(currentOption));
            loggedEvent.append(" is selected");
            emit logEvent(loggedEvent);
            emit newModeRequest(2+currentOption); //2 is an offset to account for strategySwitch::mode
            return;
        break;
    }

    playSelect->hide();
    scoreSelect->hide();
    quitSelect->hide();

    switch(currentOption)
    {
        case 0:
            playSelect->show();
        break;
        case 1:
            scoreSelect->show();
        break;
        case 2:
            quitSelect->show();
        break;
    }
}
