cmake_minimum_required(VERSION 3.20)
project(CoreNumeric)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ejecutable principal
add_executable(CoreNumeric
    main.cpp
)

# ejecutable de tests
add_executable(Tests
    test.cpp
)
