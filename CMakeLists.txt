#----------------------------------------------#
#-----------------CMake Config-----------------#
#----------------------------------------------#

# Minimale Version des Buildsystems
cmake_minimum_required(VERSION 3.16)
# Name des Projekts
project(talossolver)

#----------------------------------------------#
#-------------------Options--------------------#
#----------------------------------------------#

# Setzte verwendeten C++-Standard auf C++17
set(CMAKE_CXX_STANDARD 17)
# Optional: Baue mit Debugsymbolen / Optimierung
set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_BUILD_TYPE Release)
# Optional: Prüfe alle Targets auf Speicherlecks
# add_compile_options(-fsanitize=address)
# add_link_options(-fsanitize=address)

# Füge Includeverzeichnisse hinzu
include_directories(include)
include_directories(external)
# Legt die Variable SRC_FILES an, die alle
# .cpp-Dateien des Projekts benennt,
# die in Verzeichnis src/ liegen.
file(GLOB SRC_FILES
  ${PROJECT_SOURCE_DIR}/src/*.cpp)

#----------------------------------------------#
#----------------Build Project-----------------#
#----------------------------------------------#

# Baue das Programm 'demo' aus den Quellen
# examples/demo.cpp und allen Quelldateien in
# SRC_FILES (also alle im Verzeichnis src/)
add_executable(demo
  examples/demo.cpp
  ${SRC_FILES}
)

#----------------------------------------------#
#----------Download and use GoogleTest---------#
#----------------------------------------------#

# Use CMakes FetchContent
include(FetchContent)
# Workaround for CMake >= 3.24
# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
  cmake_policy(SET CMP0135 NEW)
endif()

# Download GoogleTest (we use version 1.12.1)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# Workaround for Windows:
# Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Include CMake configuration of GoogleTest
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# Enable GoogleTest
enable_testing()

#----------------------------------------------#
#------------------Build Tests-----------------#
#----------------------------------------------#

#Declare test program test_board
add_executable(test_board tests/test_board.cpp ${SRC_FILES})
target_link_libraries(test_board GTest::gtest_main)
gtest_discover_tests(test_board)

#Declare test program test_sigil
add_executable(test_sigil tests/test_sigil.cpp ${SRC_FILES})
target_link_libraries(test_sigil GTest::gtest_main)
gtest_discover_tests(test_sigil)