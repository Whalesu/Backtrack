cmake_minimum_required(VERSION 3.10)
PROJECT (Backtrack)
ADD_SUBDIRECTORY(src bin)

INSTALL(FILES COPYRIGHT README DESTINATION share/doc/cmake/Backtrack)
INSTALL(PROGRAMS runBacktrack.sh DESTINATION bin)
INSTALL(DIRECTORY doc/ DESTINATION share/doc/cmake/Backtrack)
