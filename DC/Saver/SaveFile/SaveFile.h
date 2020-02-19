#include "../../Level/Floor/Floor.h"
#include <time.h>



class SaveFile{
private:
    
    //the character being saved
    Player Character;

    //save Name
    string FileName;

    //Saved Characters Name
    string CharacterName;

    //Time
    string SaveTime;

    //can add more later

public:
    //constructor
    SaveFile(Player p,string fname);

    //returns the time of the save
    string getTime();
    
    //returns the saved Character
    Player getCharacter();

    //returns the saved characters name
    string getCharacterName();

    //returns the save file name
    string getFileName();
};