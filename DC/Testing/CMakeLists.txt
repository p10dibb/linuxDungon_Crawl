cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(executeTests  main_test.cpp  
../ActiveEffects/ActiveEffects.cpp ../ActiveEffects/ActiveEffects.h  ../ActiveEffects/ActiveEffects_test.cpp 
../Creatures/Creature/Creature.cpp ../Creatures/Creature/Creature.h ../Creatures/Creature/Creature_test.cpp 
../Items/Item/Item.h ../Items/Item/Item.cpp ../Items/Item/Item_test.cpp 
../Items/Armor/Armor.cpp ../Items/Armor/Armor_test.cpp ../Items/Armor/Armor.h 
../Items/Weapon/Weapon.h ../Items/Weapon/Weapon.cpp ../Items/Weapon/Weapon_test.cpp
../Creatures/Biped/Biped.h ../Creatures/Biped/Biped.cpp ../Creatures/Biped/Biped_test.cpp 
../Creatures/Zombie/Zombie.h ../Creatures/Zombie/Zombie.cpp   ../Creatures/Zombie/Zombie_test.cpp
../Items/Potion/Potion.h ../Items/Potion/Potion.cpp  ../Items/Potion/Potion_test.cpp 
../Spawner/Spawner.cpp ../Spawner/Spawner.h ../Spawner/SpawnerWeapons.cpp ../Spawner/SpawnerPotion.cpp ../Spawner/SpawnerArmor.cpp ../Spawner/SpawnerSpecializedItems.cpp 
../Creatures/Player/Player.h ../Creatures/Player/Player.cpp  ../Creatures/Player/Player_test.cpp 
../Creatures/Player/PlayerGetSet.cpp ../Creatures/Player/PlayerGetSet_test.cpp 
../Creatures/Player/PlayerInventory.cpp ../Creatures/Player/PlayerInventory_test.cpp 
../Creatures/Player/PlayerStats.cpp 
../Shop/Shop.h ../Shop/Shop.cpp 
../Combat/Combat.h ../Combat/Combat.cpp 
../Level/Room/Room.h ../Level/Room/Room.cpp 
../Level/Floor/Floor.h ../Level/Floor/Floor.cpp 
../DamageTypes/DamageTypes.h ../DamageTypes/DamageTypes_test.cpp ../DamageTypes/DamageTypes.cpp 
../Dungon_Crawler/Dungon_Crawler.h ../Dungon_Crawler/Dungon_Crawler.cpp  )
target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)