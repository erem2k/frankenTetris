#ifndef TETRISLOGGER_H
#define TETRISLOGGER_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QTime>

class tetrisLogger: public QObject
{
    Q_OBJECT
public:
    static tetrisLogger& Instance();
public slots:
    void logEvent(QString);
private:
    QFile *logFile;

    tetrisLogger();
    tetrisLogger(tetrisLogger const&);
    tetrisLogger& operator=(tetrisLogger const&);
    ~tetrisLogger();
};

#endif // TETRISLOGGER_H
