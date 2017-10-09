#ifndef HIGHSCOREWIDGET_H
#define HIGHSCOREWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QMovie>
#include <QPixmap>
#include <QKeyEvent>
#include "highscoresinteraction.h"
#include "basewidget.h"

class highscoreWidget : public QWidget
{
    Q_OBJECT
private:
    QLabel *uiBar, *mainLabel, *noScores;

public:
    highscoreWidget(QWidget *parent = 0);
signals:
    void newModeRequest(int);
    void logEvent(QString);
protected:
    void keyPressEvent(QKeyEvent *event) final;
};

#endif // HIGHSCOREWIDGET_H
