cmake_minimum_required(VERSION 3.10)

project(ATMSystem)

set(CMAKE_CXX_STANDARD 14)

# Add source files
set(SOURCES
    src/main.cpp
    src/ATMSystem.cpp
    src/Admin.cpp
    src/User.cpp
)

# Add header files
set(HEADERS
    include/ATMSystem.h
    include/Admin.h
    include/User.h
)

add_executable(ATMSystem ${SOURCES} ${HEADERS})
