#ifndef TETRISWINDOW_H
#define TETRISWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QPixmap>
#include "strategyswitch.h"
#include "tetrislogger.h"

class TetrisWindow : public QMainWindow
{
    Q_OBJECT
private:
    QPixmap *backgroundTitlePixmap, *bgMovingCloudsPixmap, *bgCathedralPixmap;
    strategySwitch WindowMode;
public:
    TetrisWindow(QWidget *parent = 0);
public slots:
    void strategyUpdated(int);
signals:
    void logEvent(QString);
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};

#endif // TETRISWINDOW_H
