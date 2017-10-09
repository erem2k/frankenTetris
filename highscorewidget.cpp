#include "highscorewidget.h"

highscoreWidget::highscoreWidget(QWidget *parent): QWidget(parent)
{
    this->setGeometry(0,0,512,512);
    this->setFocus();

    this->mainLabel=new QLabel(this);
    this->noScores=new QLabel(this);

    this->mainLabel->setGeometry(0,0,512,512);
    this->noScores->setGeometry(86,255,340,16);

    this->mainLabel->setPixmap(QPixmap(":/images/resources/highScores/mainBoard.png"));
    this->noScores->setPixmap(QPixmap(":/images/resources/highScores/noscores.png"));

    connect(this,SIGNAL(logEvent(QString)),&(tetrisLogger::Instance()),SLOT(logEvent(QString)));
}

void highscoreWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape)
        emit newModeRequest(1);
}
