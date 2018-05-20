cmake_minimum_required(VERSION 3.6)
project(The_Lord_Of_the_Rings)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(INCLUDE
        include/Game.h
        include/Side.h
        include/Army.h
        include/ArmyBuilder.h
        include/ArmyFactory.h
        include/ArmyUnit.h
        include/User.h)

set(SOURCE
        src/User.cpp
        src/Army.cpp
        src/Game.cpp
        src/ArmyUnit.cpp
        src/ArmyBuilder.cpp
        src/ArmyFactory.cpp
        run.cpp
    )

add_executable(The_Lord_Of_the_Rings ${INCLUDE} ${SOURCE})