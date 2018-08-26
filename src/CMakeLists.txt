cmake_minimum_required(VERSION 3.10)
PROJECT (Backtrack)
SET(SRC_LIST BacktrackMain.cpp Backtrack.cpp Maze.cpp Position.cpp)

MESSAGE(STATUS "This is BINARY dir" ${Backtrack_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir" ${Backtrack_SOURCE_DIR})
ADD_EXECUTABLE(Backtrack ${SRC_LIST})
