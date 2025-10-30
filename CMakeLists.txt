cmake_minimum_required(VERSION 3.10)
project(blackcpp CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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


if(UNIX AND NOT APPLE)
    target_compile_options(blackcpp PRIVATE -Wall -Wextra -std=c++11)
endif()


if(WIN32)
    target_link_libraries(blackcpp)
else()
    target_link_libraries(blackcpp)
endif()