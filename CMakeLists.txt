cmake_minimum_required(VERSION 3.10)
project(blackcpp CXX)

set(PROJECT_SOURCES
    main.cpp
    src/Card.cpp
    src/Deck.cpp
    src/Game.cpp
    src/Network.cpp
    src/Player.cpp
    src/UI.cpp
)

add_executable(blackcpp ${PROJECT_SOURCES})