cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(DungonCrawl)

add_executable(Runner  ../Main.cpp 
../ActiveEffects/ActiveEffects.cpp ../ActiveEffects/ActiveEffects.h 
../Creatures/Creature/Creature.cpp ../Creatures/Creature/Creature.h 
../Items/Item/Item.h ../Items/Item/Item.cpp 
../Items/Armor/Armor.cpp ../Items/Armor/Armor.h 
../Items/Weapon/Weapon.h ../Items/Weapon/Weapon.cpp 
../Creatures/Biped/Biped.h ../Creatures/Biped/Biped.cpp 
../Creatures/Zombie/Zombie.h ../Creatures/Zombie/Zombie.cpp 
../Items/Potion/Potion.h ../Items/Potion/Potion.cpp 
../LootBox/LootBox.h ../LootBox/LootBox.cpp 
../Spawner/Spawner.cpp ../Spawner/Spawner.h ../Spawner/SpawnerWeapons.cpp ../Spawner/SpawnerPotion.cpp ../Spawner/SpawnerArmor.cpp ../Spawner/SpawnerSpecializedItems.cpp 
../Creatures/Player/Player.h ../Creatures/Player/Player.cpp ../Creatures/Player/PlayerGetSet.cpp ../Creatures/Player/PlayerInventory.cpp ../Creatures/Player/PlayerStats.cpp 
../Shop/Shop.h ../Shop/Shop.cpp 
../Combat/Combat.h ../Combat/Combat.cpp 
../Level/Room/Room.h ../Level/Room/Room.cpp 
../Level/Floor/Floor.h ../Level/Floor/Floor.cpp 
../DamageTypes/DamageTypes.h ../DamageTypes/DamageTypes.cpp 
../Dungon_Crawler/Dungon_Crawler.h ../Dungon_Crawler/Dungon_Crawler.cpp )