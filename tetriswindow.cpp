#include "tetriswindow.h"

TetrisWindow::TetrisWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Tetris: The Soviet Mind Game");
    this->setFixedSize(512,512);

    this->backgroundTitlePixmap=new QPixmap(":/images/resources/background/backgroundTitle.png");
    this->bgMovingCloudsPixmap=new QPixmap(":/images/resources/background/backgroundClouds.png");
    this->bgCathedralPixmap=new QPixmap(":/images/resources/background/backgroundCathedral.png");

    QTimer *timer = new QTimer(this);
    timer->start(1000);

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(&WindowMode, SIGNAL(newMode(int)), this, SLOT(strategyUpdated(int)));

    connect(this,SIGNAL(logEvent(QString)),&(tetrisLogger::Instance()),SLOT(logEvent(QString)));

    WindowMode.setMode(strategySwitch::mode::Loading,this);
    emit logEvent("Main Window Constructed!");
}

/*-----------EVENTS---------------*/
void TetrisWindow::paintEvent(QPaintEvent *e)
{
    static unsigned int timesFired=0;

    const float cloudStartPos[]={-484,155};
    float cloudCurrentPos[]={(cloudStartPos[0]+timesFired),cloudStartPos[1]};

    QPainter painter(this);

    painter.drawPixmap(0,0,*backgroundTitlePixmap); //Non-optimal
    painter.drawPixmap(cloudCurrentPos[0],cloudCurrentPos[1],*bgMovingCloudsPixmap);
    painter.drawPixmap(298,150,*bgCathedralPixmap);

    timesFired++;
    if(cloudCurrentPos[0]>=0) timesFired=0;
}

/*-----------SLOTS----------------*/
void TetrisWindow::strategyUpdated(int newStrategyCode)
{
    WindowMode.setMode((strategySwitch::mode)newStrategyCode,this);
}
