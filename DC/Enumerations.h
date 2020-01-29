#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
//#include <conio.h>
using namespace::std;


//Directional Enumeration;
enum Direction_enum {Left_Direction, Up_Direction, Right_Direction, Down_Direction, No_Direction};

//Types of Active Effect Described in ActiveEffects.h
enum EffectTypes_enum {NULL_EffectTypes,DamageOverTime_EffectTypes,DeBuff_EffectTypes,Buff_EffectTypes,Combat_EffectTypes,Resistance_EffectTypes};

//Types of Effects  Described in ActiveEffects.h
enum Effects_enum {NULL_Effects,		//NULL
Burning_Effects, Bleeding_Effects, Poison_Effects,    //Damage over Time
Slowed_Effects,Dazed_Effects,Weakness_Effects,BattleFatigue_Effects, //De-Bebuff
SpeedBoost_Effects,DamageBoost_Effects,DefenseBoost_Effects,	//Buffs
FireResistance_Effects, StabbingResistance_Effects,BluntResistance_Effects, NormalResistance_Effects,PoisonResistance_Effects, //Damage Resistance
Bezerk_Effects, DefensiveStance_Effects, QuickStrike_Effects,Swordsman_Effects,AnimalFury_Effects}; //Combat effects

//Types of Damage Described in DamageTypes.h
enum DamageTypes_enum{NULL_DamageType,Normal_DamageType,Fire_DamageType,Stabbing_DamageType,Blunt_DamageType,Critical_DamageType,Poison_DamageType};

//Types of Armor Classes
enum ArmorClass_enum {  NULL_ArmorClass,Light_ArmorClass, Normal_ArmorClass, Heavy_ArmorClass };

//Types of Armor
enum ArmorType_enum {NULL_ArmorType, Helmet_ArmorType, Chest_ArmorType, Gloves_ArmorType, Pants_ArmorType, Boots_ArmorType};

//Item Rarity Level
enum ItemRarity_enum{Common_ItemRarity, UnCommon_ItemRarity, Rare_ItemRarity,Legendary_ItemRarity,Unique_ItemRarity,DEVELOPER_ItemRarity};

//Types of Potions Described in Potions.h
enum PotionTypes_enum { NULL_PotionType, 
Health_PotionType, CureActiveEffects_PotionType,CureNegativeEffects_PotionType,		//benefits the creatures
SpeedStat_PotionType, StrengthStat_PotionType, MaxHealthStat_PotionType, DefenseStat_PotionType,DamageStat_PotionType,StaminaStat_PotionType, //increases stats
IncreaseSpeed_PotionType,IncreaseDamage_PotionType,IncreaseDefense_PotionType,//buff potions
NormalResistance_PotionType, FireResistance_PotionType,PoisonResistance_PotonType,BluntResistance_PotionType,StabbingResistance_PotionType };  //Resistance Potions

//Types of Weapons Described in Weapon.h
enum WeaponTypes_enum{NULL_WeaponType,Sword_WeaponType, Shield_WeaponType, Dagger_WeaponType, Axe_WeaponType, Claw_WeaponType};

//the markers for Room maps
enum RoomPieces_enum{Empty_RoomPieces, Wall_RoomPieces, UpDoor_RoomPieces, RightDoor_RoomPieces, LeftDoor_RoomPieces, DownDoor_RoomPieces, Enemy_RoomPieces, Shop_RoomPieces, Loot_RoomPieces, Player_RoomPieces};