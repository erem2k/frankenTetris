
#ifndef TetrisBoard_H
#define TetrisBoard_H

#include <QBasicTimer>
#include <QWidget>
#include <QPointer>

#include "tetrispiece.h"

QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

//! [0]
class TetrisBoard : public QWidget
{
    Q_OBJECT

public:
    TetrisBoard(QWidget *parent = 0);

    bool isStarted;
    bool isPaused;

public slots:
    void start();
    void pause();

signals:
    void scoreChanged(int score);
    void levelChanged(int level);
    void linesRemovedChanged(int numLines);
    void gamePaused();
    void gameStarted();
    void gameOver(int,int);
    void signalNextPiece(QPixmap);
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;

private:
    enum { BoardWidth = 10, BoardHeight = 22 };

    TetrisShape &shapeAt(int x, int y) { return board[(y * BoardWidth) + x]; }
    int timeoutTime() { return 1000 / (1 + level); }
    int squareWidth() { return contentsRect().width() / BoardWidth; }
    int squareHeight() { return contentsRect().height() / BoardHeight; }
    void clearBoard();
    void dropDown();
    void oneLineDown();
    void pieceDropped(int dropHeight);
    void removeFullLines();
    void newPiece();
    void showNextPiece();
    bool tryMove(const TetrisPiece &newPiece, int newX, int newY);
    void drawSquare(QPainter &painter, int x, int y, TetrisShape shape);

    QBasicTimer timer;
    bool isWaitingAfterLine;
    TetrisPiece curPiece;
    TetrisPiece nextPiece;
    int curX;
    int curY;
    int numLinesRemoved;
    int numPiecesDropped;
    int score;
    int level;
    TetrisShape board[BoardWidth * BoardHeight];
};
//! [1]

#endif
#ifndef TETRISBOARD_H
#define TETRISBOARD_H



#endif // TETRISBOARD_H
