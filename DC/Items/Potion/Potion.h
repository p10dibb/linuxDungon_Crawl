#include "../Item/Item.h"
#include "../../Creatures/Creature/Creature.h"
						//Nothing	    resores health,   adds one speed point,adds 1 strength point,increases combat speed, increases combat Damage, increases combat Defense , removes all active effects
enum PotionTypes_enum { NULL_PotionType, Health_PotionType, Speed_PotionType, Strength_PotionType,IncreaseSpeed_PotionType,IncreaseDamage_PotionType,IncreaseDefense_PotionType, CureActiveEffects_PotionType };


//potions can only be used by humanoids
class Potion :public Item {

private:
	//the 
	PotionTypes_enum Type;
	//multiplier for restoration
	int Tier;
	

	int BaseBooster ;

	//increases current Health
	bool UseHealth(Creature *c);
	//increases speed skill point by tier
	bool UseSpeedBooster(Creature *h);
	//increases strength skill point by Tier
	bool UseStrengthBooster(Creature *p);
	//adds a speed mutiplier of Tier active effect 
	bool UseIncreaseSpeed(Creature *p);
	//adds a damage multiplier of Tier active effect
	bool UseIncreaseDamage(Creature *p);
	//adds a Damage reduction multiplier of Tier active effect
	bool UseIncreaseDefense(Creature *p);
	//removes all active effects both good and bad
	bool UseCureActiveEffects(Creature *p);
	
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