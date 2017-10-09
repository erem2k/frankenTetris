#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QFont>
#include <QFontDatabase>
#include <QString>
#include <QKeyEvent>
#include <QLineEdit>
#include <QPushButton>
#include "highscoresinteraction.h"
#include "basewidget.h"
#include "tetrisboard.h"
#include "tetrispiece.h"
#include "tetrislogger.h"

class gameWidget : public QWidget
{
    Q_OBJECT
private:
    TetrisBoard *Board;
    bool pmCurrentOption, pauseMenuRan, gameOverInitiated;
    int endgameLines, endgameScore;
    QLabel *backgroundLabel, *newgameLabel, *scoreLabel, *linesDeletedLabel, *nextPieceLabel;
    QLabel *pauseMenuLabel, *pmNoSelect, *pmYesSelect;
    QLabel *gameOverBg, *goScoreLabel, *goLinesLabel;
    QLineEdit *goNameLine;
    QPushButton *confirmButton;

    void prepareLabels();
    void establishConnections();
public:
    gameWidget(QWidget *parent = 0);
private slots:
    void scoreUpdated(int);
    void linesUpdated(int);
    void pauseTriggered();
    void gameStarted();
    void gameOver(int,int);
    void gameOverButtonClicked();
    void receiveNextPiece(QPixmap);
signals:
    void newModeRequest(int);
    void logEvent(QString);
protected:
    void keyPressEvent(QKeyEvent *event) final;
};

#endif // GAMEWIDGET_H
