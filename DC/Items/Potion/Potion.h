#include "../Item/Item.h"
#include "../../Creatures/Creature/Creature.h"

enum PotionTypes_enum { NULL_PotionType, Health_PotionType, Speed_PotionType, Strength_PotionType };


//potions can only be used by humanoids
class Potion :public Item {

private:
	//the 
	PotionTypes_enum Type;
	//multiplier for restoration
	int Tier;
	

	int BaseBooster ;

	bool UseHealth(Creature *c);
	bool UseSpeedBooster(Creature *h);
	bool UseStrengthBooster(Creature *p);
public:
	Potion();
	bool Use(Creature *c);

	void DisplayDetails();

	PotionTypes_enum getType();
	void setType(PotionTypes_enum t);
	int getTier();
	void setTier(int t);
	int getBaseBooster();
	void setBaseBooster(int b);



	


};