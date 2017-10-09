#include "gamewidget.h"
#include <iostream>
#include <vector>

gameWidget::gameWidget(QWidget *parent): QWidget(parent)
{
    int id = QFontDatabase::addApplicationFont(":/fonts/resources/gameFont.otf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont gameFont24(family);
    QPalette lineeditText;
    lineeditText.setColor(QPalette::Text,*(new QColor(38,73,79)));

    gameFont24.setPointSize(24);

    this->setGeometry(0,0,512,512);
    this->setFocusPolicy(Qt::NoFocus);

    this->pauseMenuRan=false;
    this->gameOverInitiated=false;

    this->prepareLabels();

    this->goNameLine= new QLineEdit(this);
    this->confirmButton= new QPushButton(this);
    this->Board=new TetrisBoard(this);

    this->confirmButton->setGeometry(85,457,342,36);
    this->confirmButton->setText("confirm");
    this->confirmButton->setFont(gameFont24);
    this->confirmButton->setStyleSheet("background-color: transparent;");
    this->confirmButton->setStyleSheet("color: #26494f");
    this->confirmButton->setEnabled(false);
    this->confirmButton->hide();

    this->goNameLine->setGeometry(175,385,175,50);
    this->goNameLine->setFrame(false);
    this->goNameLine->setStyleSheet("* { background-color: #e6f2f3 }");
    this->goNameLine->setFont(gameFont24);
    this->goNameLine->setMaxLength(7);
    this->goNameLine->setPalette(lineeditText);
    this->goNameLine->setEnabled(false);
    this->goNameLine->hide();

    Board->setFocus();
    Board->setGeometry(44,7,239,496);

    this->gameOverBg->raise();
    this->goScoreLabel->raise();
    this->goLinesLabel->raise();
    this->goNameLine->raise();
    this->confirmButton->raise();

    this->pauseMenuLabel->raise();
    this->pmNoSelect->raise();
    this->pmYesSelect->raise();

    this->establishConnections();

    Board->show();
}

/*----------------PRIVATE---------------*/
void gameWidget::prepareLabels()
{
    int id = QFontDatabase::addApplicationFont(":/fonts/resources/gameFont.otf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont gameFont20(family), gameFont24(family);

    gameFont20.setPointSize(20);
    gameFont24.setPointSize(24);

    backgroundLabel=new QLabel(this);
    newgameLabel=new QLabel(this);
    scoreLabel=new QLabel(this);
    linesDeletedLabel=new QLabel(this);
    nextPieceLabel= new QLabel(this);

    pauseMenuLabel=new QLabel(this);
    pmNoSelect=new QLabel(this);
    pmYesSelect=new QLabel(this);

    gameOverBg= new QLabel(this);
    goScoreLabel= new QLabel(this);
    goLinesLabel= new QLabel(this);

    backgroundLabel->setGeometry(0,0,512,512);
    newgameLabel->setGeometry(331,80,175,228);
    scoreLabel->setGeometry(347,78,(139),(14+10));
    linesDeletedLabel->setGeometry(382,165,(74),(16+10));
    nextPieceLabel->setGeometry(365,232,104,104);

    gameOverBg->setGeometry(0,0,512,512);
    goScoreLabel->setGeometry(318,230,115,31);
    goLinesLabel->setGeometry(347,138,68,31);

    nextPieceLabel->setAlignment(Qt::AlignCenter);

    pauseMenuLabel->setGeometry(0,0,512,512);
    pmNoSelect->setGeometry(275,262,95,31);
    pmYesSelect->setGeometry(133,262,114,31);

    backgroundLabel->setPixmap(*(new QPixmap(":/images/resources/playingField/playingField.png")));
    newgameLabel->setPixmap(*(new QPixmap(":/images/resources/playingField/playStart.png")));
    gameOverBg->setPixmap(*(new QPixmap(":/images/resources/gameover/gameover.png")));

    pauseMenuLabel->setPixmap(*(new QPixmap(":/images/resources/pause/pauseBar.png")));
    pmNoSelect->setPixmap(*(new QPixmap(":/images/resources/quitMenu/noSelect.png")));
    pmYesSelect->setPixmap(*(new QPixmap(":/images/resources/quitMenu/yesSelect.png")));

    scoreLabel->setFont(gameFont20);
    linesDeletedLabel->setFont(gameFont24);
    goScoreLabel->setFont(gameFont24);
    goLinesLabel->setFont(gameFont24);

    scoreLabel->setText("0");
    linesDeletedLabel->setText("0");

    goScoreLabel->setText("0");
    goLinesLabel->setText("0");

    scoreLabel->setAlignment(Qt::AlignCenter);
    linesDeletedLabel->setAlignment(Qt::AlignCenter);

    goScoreLabel->setAlignment(Qt::AlignCenter);
    goLinesLabel->setAlignment(Qt::AlignCenter);

    scoreLabel->setStyleSheet("color: #26494f");
    linesDeletedLabel->setStyleSheet("color: #26494f");

    goScoreLabel->setStyleSheet("color: #26494f");
    goLinesLabel->setStyleSheet("color: #26494f");

    scoreLabel->hide();
    linesDeletedLabel->hide();

    pauseMenuLabel->hide();
    pmNoSelect->hide();
    pmYesSelect->hide();

    gameOverBg->raise();
    goScoreLabel->raise();
    goLinesLabel->raise();

    gameOverBg->hide();
    goScoreLabel->hide();
    goLinesLabel->hide();

}

void gameWidget::establishConnections()
{
    this->connect(Board, SIGNAL(scoreChanged(int)), this, SLOT(scoreUpdated(int)));
    this->connect(Board, SIGNAL(linesRemovedChanged(int)), this, SLOT(linesUpdated(int)));
    this->connect(Board, SIGNAL(gamePaused()), this, SLOT(pauseTriggered()));
    this->connect(Board, SIGNAL(gameStarted()), this, SLOT(gameStarted()));
    this->connect(Board, SIGNAL(signalNextPiece(QPixmap)), this, SLOT(receiveNextPiece(QPixmap)));
    this->connect(Board, SIGNAL(gameOver(int,int)), this, SLOT(gameOver(int,int)));
    this->connect(confirmButton, SIGNAL(clicked(bool)), this, SLOT(gameOverButtonClicked()));

    this->connect(this, SIGNAL(logEvent(QString)),&(tetrisLogger::Instance()),SLOT(logEvent(QString)));
}

/*------------PRIVATE SLOTS-------------*/
void gameWidget::scoreUpdated(int newScore)
{
    scoreLabel->setText(QString::number(newScore));
}

void gameWidget::linesUpdated(int newLines)
{
    linesDeletedLabel->setText(QString::number(newLines));
}

void gameWidget::pauseTriggered()
{
    this->setFocusPolicy(Qt::StrongFocus);
    this->setFocus();

    this->pmCurrentOption=false;
    this->pauseMenuLabel->show();
    this->pmNoSelect->show();

    this->pauseMenuRan=true;
}

void gameWidget::gameOver(int overScore, int overLines)
{
    gameOverBg->show();

    goLinesLabel->setText(QString::number(overLines));
    goScoreLabel->setText(QString::number(overScore));

    goScoreLabel->show();
    goLinesLabel->show();

    goNameLine->setEnabled(true);
    goNameLine->show();

    confirmButton->setEnabled(true);
    confirmButton->show();

    gameOverInitiated=true;

    endgameLines=overLines;
    endgameScore=overScore;
}

void gameWidget::gameStarted()
{
    scoreLabel->show();
    linesDeletedLabel->show();
    newgameLabel->hide();
}

void gameWidget::gameOverButtonClicked()
{
    highscoresInteraction::Instance().writeEntry(goNameLine->text(),endgameScore,endgameLines);
    emit newModeRequest(1);
}

void gameWidget::receiveNextPiece(QPixmap nextPiecePixmap)
{
    nextPieceLabel->setPixmap(nextPiecePixmap);
}

/*------------EVENT HANDLING-----------*/
void gameWidget::keyPressEvent(QKeyEvent *event)
{
    if(Board->isPaused&&pauseMenuRan)
    {
        switch(event->key())
        {
            case Qt::Key_Right:
                if(pmCurrentOption)
                {
                    pmCurrentOption=false;
                    pmYesSelect->hide();
                    pmNoSelect->show();
                }
            break;
            case Qt::Key_Left:
                if(!pmCurrentOption)
                {
                    pmCurrentOption=true;
                    pmNoSelect->hide();
                    pmYesSelect->show();
                }
            break;
            case Qt::Key_Space:
                if(pmCurrentOption)
            {
                emit logEvent("Game: Pause - Going back to main menu!");
                emit newModeRequest(1);
            }
                else
                {
                    emit logEvent("Game: Pause - Going back to game");

                    pauseMenuRan=false;

                    this->setFocusPolicy(Qt::NoFocus);
                    Board->setFocus();

                    pauseMenuLabel->hide();
                    pmNoSelect->hide();
                    pmYesSelect->hide();
                    Board->pause();
                }
            break;
        }
    }
}

