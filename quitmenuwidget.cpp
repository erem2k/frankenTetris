#include "quitmenuwidget.h"

quitMenuWidget::quitMenuWidget(QWidget *parent): QWidget(parent)
{
    this->currentOption=true;

    this->setGeometry(0,367,512,147);
    this->setFocus();

    this->textLabel=new QLabel(this);
    this->yesSelect=new QLabel(this);
    this->noSelect=new QLabel(this);

    this->textLabel->setGeometry(0,0,512,147);
    this->yesSelect->setGeometry(133,82,114,31);
    this->noSelect->setGeometry(275,82,95,31);

    this->textLabel->setPixmap(QPixmap(":/images/resources/quitMenu/quitMenu.png"));
    this->yesSelect->setPixmap(QPixmap(":/images/resources/quitMenu/yesSelect.png"));
    this->noSelect->setPixmap(QPixmap(":/images/resources/quitMenu/noSelect.png"));


    this->textLabel->show();
    this->yesSelect->show();
    this->noSelect->hide();

    connect(this,SIGNAL(logEvent(QString)),&(tetrisLogger::Instance()),SLOT(logEvent(QString)));
}

void quitMenuWidget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Right:
            if(currentOption)
            {
                currentOption=false;
                yesSelect->hide();
                noSelect->show();
            }
        break;
        case Qt::Key_Left:
            if(!currentOption)
            {
                currentOption=true;
                noSelect->hide();
                yesSelect->show();
            }
        break;
        case Qt::Key_Space:
            if(currentOption)
            {
                emit logEvent("QuitMenu: Application quits!");
                QApplication::quit();
            }
            else
            {
                emit logEvent("QuitMenu: Going back to main menu");
                emit newModeRequest(1);     //No selected and activated - going back to main menu
            }
        break;
    }
}
