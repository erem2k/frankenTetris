#include "tetrislogger.h"

tetrisLogger& tetrisLogger::Instance()
{
    static tetrisLogger SingleInstance;
    return SingleInstance;
}

void tetrisLogger::logEvent(QString eventText)
{
    QTextStream currentStream(logFile);

    QString eventLogString=QTime::currentTime().toString().append(" ");
    eventLogString.append(eventText);
    eventLogString.append("\n");

    currentStream <<eventLogString;

}

tetrisLogger::tetrisLogger()
{
    this->logFile=new QFile("log.dat");
    this->logFile->open(QIODevice::ReadWrite);
}
tetrisLogger::~tetrisLogger() {}

