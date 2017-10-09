#ifndef QUITMENUWIDGET_H
#define QUITMENUWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QKeyEvent>
#include <QApplication>
#include "basewidget.h"

class quitMenuWidget : public QWidget
{
    Q_OBJECT
private:
    bool currentOption;
    QLabel *textLabel, *noSelect, *yesSelect;
public:
    quitMenuWidget(QWidget *parent = 0);
signals:
    void newModeRequest(int);
    void logEvent(QString);
protected:
    void keyPressEvent(QKeyEvent *event) final;
};

#endif // QUITMENUWIDGET_H
