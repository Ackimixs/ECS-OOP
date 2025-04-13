
cmake_minimum_required(VERSION 3.10)
project(UpgradedECSGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(upgraded_ecs_game
    main.cpp
)

target_include_directories(upgraded_ecs_game PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/core ${CMAKE_CURRENT_SOURCE_DIR}/systems)
