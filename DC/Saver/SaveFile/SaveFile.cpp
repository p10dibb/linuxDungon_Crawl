#include "SaveFile.h"

//constructor
SaveFile::SaveFile(Player p, string fname)
{
    time_t my_time = time(NULL);
    this->Character=p;
    this->FileName=fname;
    this->SaveTime=ctime(&my_time);
    this->CharacterName=p.getName();
    
    //removes the new line from time
    this->SaveTime.pop_back();
}
//returns the time of the save
string SaveFile::getTime() {
    return this->SaveTime;
}

//returns the saved Character
Player SaveFile::getCharacter() {
    return this->Character;
}

//returns the saved characters name
string SaveFile::getCharacterName() {
    return this->CharacterName;
}

//returns the save file name
string SaveFile::getFileName() {
    return this->FileName;
}