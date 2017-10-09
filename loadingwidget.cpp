#include "loadingwidget.h"

loadingWidget::loadingWidget(QWidget *parent): QWidget(parent)
{
    this->setGeometry(0,367,512,145);
    this->setFocus();

    this->UIBar=new QPixmap(":/images/resources/UIBar.png");
    this->loadingAnim=new QMovie(":/animations/resources/loadingAnim.gif");

    this->uibarLabel=new QLabel(this);
    this->animLabel=new QLabel(this);

    this->animLabel->setGeometry(220,41,64,64);
    this->uibarLabel->setGeometry(0,0,512,145);

    this->animLabel->setMovie(loadingAnim);
    this->uibarLabel->setPixmap(*UIBar);

    this->loadingAnim->start();


    this->uibarLabel->show();
    this->animLabel->show();

    connect(this,SIGNAL(logEvent(QString)),&(tetrisLogger::Instance()),SLOT(logEvent(QString)));
}

void loadingWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Space)
    {
        emit logEvent("LoadingWidget: Loading stopped!");
        emit newModeRequest(1); //calls menu
    }
}
