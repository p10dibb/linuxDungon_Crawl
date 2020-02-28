#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 3.10)


# Enable debug symbols by default
# must be done before project() statement
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

project(myproject)

# Set version information in a config.h file
set(myproject_VERSION_MAJOR 1)
set(myproject_VERSION_MINOR 0)
configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )
include_directories("${PROJECT_BINARY_DIR}")

# Define sources and executable
set(EXECUTABLE_NAME "Runner")
add_executable(${EXECUTABLE_NAME}   ../Main.cpp 
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
../Saver/SaveFile/SaveFile.h ../Saver/SaveFile/SaveFile.cpp
../Saver/Saver.h ../Saver/Saver.cpp
../Room_Design/Room_Design.h ../Room_Design/Room_Design.cpp
../DamageTypes/DamageTypes.h ../DamageTypes/DamageTypes.cpp 
../Dungon_Crawler/Dungon_Crawler.h ../Dungon_Crawler/Dungon_Crawler.cpp)


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()


# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
