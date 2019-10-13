#include "Player.h"

//returns the amount of creatures player has killed
int Player::getCreaturesKilled(){
    return this->CreaturesKilled;
}
//increases CreaturesKilled by 1
void Player::IncrementCreaturesKilled(){
    this->CreaturesKilled+=1;
    RewardCheckCreaturesKilled();
    

}
//checks to see if the amount meets a reward requirment
int Player::RewardCheckCreaturesKilled(){

    //this is vaugue model for rewards
    Weapon* RewardWeapon;
    Armor* RewardArmor;
    int ArmourChance=-1;
    if(this->getCreaturesKilled()>1000000){
        cout<<"what are you doing with your life"<<endl;
    }else if(this->getCreaturesKilled()>10){
        
        if(rand()%2 ==0){
            RewardWeapon=spawner.CreateDagger(this->getLevel());
        }else{
            RewardArmor=spawner.CreateChest(this->getLevel(),Light_ArmorClass);
        }
       return 10;
    }
    return -1;
}

//returns the total amount of items recieved;
int Player::getItemsRecieved(){
    return this->ItemsRecieved;
}
//increments the ItemsRecieved by 1
void Player::IncrementItemsRecieved(){
    this->ItemsRecieved+=1;
    this->RewardCheckItemsRecieved();
}
//checks to see if the ItemsRecieved meets reward requirments
int Player::RewardCheckItemsRecieved(){

    return -1;
}

//returns total amount of gold Collected
int Player::getGoldCollected(){
    return this->GoldCollected;
}
//increases GoldCollected by amount
void Player::IncrementGoldCollected(int amount){
    this->GoldCollected+=amount;
}
//checks if the GoldCollected meets RewardRequirements
int Player::RewardCheckGoldCollected(){
    return -1;
}

//returns the total amount of Gold Spent
int Player::getGoldSpent(){
    return this->GoldSpent;
}
//increases GoldSpent by amount
void Player::IncrementGoldSpent(int amount){
    this->GoldSpent+=amount;
}
//checks if the GoldSpent meets reward Requirements
int Player::RewardCheckGoldSpent(){
    return -1;
}

//returns total amount of floors player has been too
int Player::getRoomsBeenToo(){
    return this->RoomsBeenToo;
}
//increases RoomsBeenToo by 1
void Player::IncrementRoomsBeenToo(){
    this->RoomsBeenToo+=1;
}
//checks if the RoomsBeenToo meets reward requirements
int Player::RewardCheckRoomsBeenToo(){
    return -1;
}

//returns total amount of damage recieved
int Player::getDamageRecieved(){
    return this->DamageRecieved;
}
//increase DamageRecieved by amount;
void Player::IncrementDamageRecieved(int amount){
    this->DamageRecieved+=amount;
}
//checks if the DamageRecieved meetsReward requirements
int Player::RewardCheckDamageRecieved(){
    return -1;
}

//returns total amount of Damage Dealt
int Player::getDamageDealt(){
    return this->DamageDealt;
}
//increases DamageDealt by amount
void Player::IncrementDamageDealt(int amount){
    this->DamageDealt+=amount;
}
// checks if DamageDealt meets reward requirements
int Player::RewardCheckDamageDealt(){
    return -1;
}

//returns largest amount of Money the player has had
int Player::getMaxGoldHeld(){
    return this->MaxGoldHeld;
}
//checks to see if MaxGold meets reqard requirements
int Player::RewardCheckMaxGoldHeld(){
    if(this->getMoney()>this->MaxGoldHeld){
        this->MaxGoldHeld=this->Money;
    }

    return -1;
}

//returns the maxDamage Dealt
int Player::getMaxDamageDealt(){
    return this->MaxDamageDealt;

}
//checks if MaxDamageDealt meets Reward Requirements
int Player::RewardCheckMaxDamageDealt(int damage){
    if(damage>this->MaxDamageDealt){
        this->MaxDamageDealt=damage;
    }
    return -1;
}

//returns total amount of potions the player has drunk
int Player::getPotionsDranked(){
    return this->PotionsDranked;
}
//increases Potion Dranked by 1
void Player::IncrementPotionDranked(){
    this->PotionsDranked+=1;
}
//checks if the PotionsDranked meets reward requirements
int Player::RewardCheckPotionDranked(){
    return -1;
}