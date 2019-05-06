cmake_minimum_required(VERSION 3.9)

project(GroupProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(GroupProject driver.cpp color_rgb.cpp color_rgb.h
        line.cpp line.h point.cpp point.h SDL_Plotter.cpp SDL_Plotter.h BruteForce.h BruteForce.cpp
        dcConvexHull.h bruteForceConvexHull.h Shapes.cpp Shapes.h Letter.cpp Letter.h
        UserInterface.h Divide_and_Conquer.h Divide_and_Conquer.cpp)
target_link_libraries(GroupProject SDL2main SDL2 SDL2_mixer)