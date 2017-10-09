#include "highscoresinteraction.h"


highscoresInteraction& highscoresInteraction::Instance()
{
    static highscoresInteraction SingleInstance;
    return SingleInstance;
}

void highscoresInteraction::writeEntry(QString recPlayer, int recScores,int recLines)
{

    highscoreEntry tempEntry;
    templateBubbleSort<highscoreEntry> sorter;

    tempEntry.playerName=recPlayer;
    tempEntry.score=recScores;
    tempEntry.lines=recLines;

    Entries.push_back(tempEntry);
    Entries=sorter(Entries);

    std::reverse(Entries.begin(),Entries.end());


}

std::vector<highscoresInteraction::highscoreEntry>  highscoresInteraction::getEntries()
{
    return Entries;
}

bool highscoresInteraction::highscoreEntry::operator >(const highscoresInteraction::highscoreEntry& A)
{
    if(this->score>A.score)
        return true;
    else
        return false;
}

highscoresInteraction::highscoresInteraction()
{
}

highscoresInteraction::~highscoresInteraction() {}

