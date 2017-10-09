#ifndef LOADINGWIDGET_H
#define LOADINGWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QMovie>
#include <QPixmap>
#include <QKeyEvent>
#include "basewidget.h"

class loadingWidget : public QWidget
{
    Q_OBJECT
private:
    QPixmap* UIBar;
    QMovie* loadingAnim;
    QLabel* animLabel, *uibarLabel;
public:
    loadingWidget(QWidget *parent = 0);
signals:
    void newModeRequest(int);
    void logEvent(QString);
protected:
    void keyPressEvent(QKeyEvent*) final;
};

#endif // LOADINGWIDGET_H
