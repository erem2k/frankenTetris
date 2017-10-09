#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QWidget>
#include "tetrislogger.h"

class baseWidget : public QWidget
{
    Q_OBJECT
public:
    baseWidget(QWidget* parent=0);
protected:
    void keyPressEvent(QKeyEvent*) {}
signals:
    void newModeRequest(int);
};

#endif // BASEWIDGET_H
