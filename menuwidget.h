#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QKeyEvent>
#include "basewidget.h"

class menuWidget : public QWidget
{
    Q_OBJECT
private:
    int currentOption;
    QLabel *uiBar, *menuText,*playSelect, *scoreSelect, *quitSelect;

public:
    menuWidget(QWidget *parent = 0);
signals:
    void newModeRequest(int);
    void logEvent(QString);
protected:
    void keyPressEvent(QKeyEvent *event) final;
};

#endif // MENUWIDGET_H
