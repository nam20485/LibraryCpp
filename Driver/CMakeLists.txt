﻿# CMakeList.txt : CMake project for LibraryCpp, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Driver "main.cpp" )

target_link_libraries(Driver "Cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Driver PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
