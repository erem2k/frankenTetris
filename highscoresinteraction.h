#ifndef HIGHSCORESINTERACTION_H
#define HIGHSCORESINTERACTION_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QTextStream>
#include "templatebubblesort.h"
#include <vector>

class highscoresInteraction: public QObject
{
    Q_OBJECT
public:
    struct highscoreEntry
    {
       QString playerName;
       int score;
       int lines;
       bool operator >(const highscoreEntry&);
    };

    static highscoresInteraction& Instance();
    void writeEntry(QString,int,int);
    std::vector<highscoreEntry>  getEntries();
private:
    std::vector<highscoreEntry> Entries;

    highscoresInteraction();
    highscoresInteraction(highscoresInteraction const&);
    highscoresInteraction& operator=(highscoresInteraction const&);
    ~highscoresInteraction();
};

#endif // HIGHSCORESINTERACTION_H

