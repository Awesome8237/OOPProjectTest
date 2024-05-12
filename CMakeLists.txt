cmake_minimum_required(VERSION 3.27)
project(SFMLTest)

set(CMAKE_CXX_STANDARD 17)

add_executable(SFMLTest main.cpp
        Bullet.h
        NormalZombie.h
        NormalZombie.h
        Peashooter.h
        Peashooter.h
        DancingZombie.h
        DancingZombie.h
        Zombie.h
        Zombie.h
        CherryBomb.h
        Plant.h
        Plant.h
        SunFlower.h
        SunFlower.h
        Sun.h
        Interface.h
        Icon.h
        ShooterPlant.h
        ShooterPlant.h
        WallNut.h
        WallNut.h
        PlantFactory.h
        PlantFactory.h
        ZombieFactory.h
        FootballZombie.h
        BackupDancerZombie.h
        Repeater.h
        FrozenPeaShooter.h
        Bullet.cpp
        Game.h
        CherryBomb.cpp
        DancingZombie.cpp
        FootballZombie.cpp
        FrozenPeaShooter.cpp
        Icon.cpp
        NormalZombie.cpp
        Peashooter.cpp
        Plant.cpp
        PlantFactory.cpp
        Repeater.cpp
        Sun.cpp
        SunFlower.cpp
        WallNut.cpp
        Zombie.cpp
        ZombieFactory.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS audio graphics window system REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(SFMLTest sfml-audio sfml-graphics sfml-window sfml-system)