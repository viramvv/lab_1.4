cmake_minimum_required(VERSION 3.20)
project(LibraryProject)

set(CMAKE_CXX_STANDARD 17)

# Завантаження Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Вказуємо вихідні файли нашого класу
set(BOOK_SOURCES Book.cpp Book.h)

# Створюємо програму для самих тестів
add_executable(LibraryTests UnitTest.cpp ${BOOK_SOURCES})

# ПІДКЛЮЧАЄМО gtest_main — це і є той самий "прихований main"
target_link_libraries(LibraryTests gtest_main)

# Створюємо звичайну програму (лабораторну)
add_executable(LibraryMain main.cpp ${BOOK_SOURCES})