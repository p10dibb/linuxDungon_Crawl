#include "Item.h"
#include "Creature.h"

enum PotionTypes { Water, Health, Speed, Strength };


//potions can only be used by humanoids
class Potion :public Item {

private:
	//the 
	PotionTypes Type;
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

	PotionTypes getType();
	void setType(PotionTypes t);
	int getTier();
	void setTier(int t);
	int getBaseBooster();
	void setBaseBooster(int b);



	


};