#include "../Item/Item.h"
#include "../../Creatures/Creature/Creature.h"
						//Nothing	    resores health,   adds one speed point,adds 1 strength point,increases combat speed, increases combat Damage, increases combat Defense , removes all active effects
enum PotionTypes_enum { NULL_PotionType, 
Health_PotionType, CureActiveEffects_PotionType,CureNegativeEffects_PotionType,		//benefits the creatures
SpeedStat_PotionType, StrengthStat_PotionType, MaxHealthStat_PotionType, DefenseStat_PotionType,DamageStat_PotionType,StaminaStat_PotionType, //increases stats
IncreaseSpeed_PotionType,IncreaseDamage_PotionType,IncreaseDefense_PotionType };  //buff potions

//Potion Descriptions-----
	//NULL: does Nothing
	//Healing-----
		//Health: restores health to creature based on the tier of the potion
		//CureActiveEffects: removes all active effects from creature
		//CureNegativeActiveEffects: (Not uet implemented) removes all DOT and debuff effects from creature
	//-----------
	//increase Stats----
		//Speed: permenentally boost the creatures speed stats by the potions tear
		//Strength: permenetally boosts the creatures strength stat by the potions tier
		//MaxHealth: Permenentally increase creatures max health by 10 *potion tier
		//Defense:  Permenentally increases defense stat by potion tier
		//Damage:  Permentally increases damage stat by potion tier
		//Stamina:  Permenetally increases stamina by potion tier
	//--------
	//Buffs------
		//IncreaseSpeed: adds a speed boost effect to the creature
		//IncreaseDamage: adds a damage boost effect to the creature
		//IncreaseDefense: adds a defence boost effect to the creature
	//--------

//-----------


//potions can only be used by humanoids
class Potion :public Item {

private:
	//the 
	PotionTypes_enum Type;
	//multiplier for restoration
	int Tier;
	

	int BaseBooster ;

	//increases current Health
	bool UseHealth(Creature *creature);
	//increases speed skill point by tier
	bool UseSpeedStat(Creature *creature);
	//increases strength skill point by Tier
	bool UseStrengthStat(Creature *creature);
	//increases strength skill point by Tier
	bool UseMaxHealthStat(Creature *creature);
	//increases strength skill point by Tier
	bool UseDefenseStat(Creature *creature);
	//increases strength skill point by Tier
	bool UseDamageStat(Creature *creature);
	//increases strength skill point by Tier
	bool UseStaminaStat(Creature *creature);


	//adds a speed mutiplier of Tier active effect 
	bool UseIncreaseSpeed(Creature *creature);
	//adds a damage multiplier of Tier active effect
	bool UseIncreaseDamage(Creature *creature);
	//adds a Damage reduction multiplier of Tier active effect
	bool UseIncreaseDefense(Creature *creature);
	
	//removes all active effects both good and bad
	bool UseCureActiveEffects(Creature *creature);
	//removes all DOT and DeBuff effects from creature
	bool UseCureNegativeEffects(Creature *creature);

	
public:
	Potion();
	bool Use(Creature *creature);

	void DisplayDetails();

	PotionTypes_enum getType();
	void setType(PotionTypes_enum t);
	int getTier();
	void setTier(int t);
	int getBaseBooster();
	void setBaseBooster(int b);

	//returns the potions name based on its type
	string getTypeName();

};