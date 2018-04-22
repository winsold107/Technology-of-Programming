cmake_minimum_required(VERSION 3.9)
project(1_task_pattern)

set(CMAKE_CXX_STANDARD 17)

add_executable(1_task_pattern source.cpp src/Game.cpp include/Game.h run.cpp src/ArmyUnit.cpp include/ArmyUnit.h src/User.cpp include/User.h include/Side.h src/Army.cpp include/Army.h src/ArmyBuilder.cpp include/ArmyBuilder.h include/ArmyFactory.cpp include/ArmyFactory.h)