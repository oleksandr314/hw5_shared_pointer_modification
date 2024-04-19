cmake_minimum_required(VERSION 3.15)
project(MySharedPtr)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Додаємо папку src для знаходження вашого CustomClass.h
include_directories(src)

# Додаємо папку example та файл main.cpp
add_executable(example example/main.cpp)

# Додаємо папку tests та файл tests.cpp
add_executable(tests tests/tests.cpp src/)

# Підключаємо Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Лінкуємо тестовий виконуваний файл з gtest та вашим класом
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)

