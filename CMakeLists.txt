#----------------------------------------------#
#-----Konfiguration des Buildsystems CMake-----#
#----------------------------------------------#

# Minimale Version des Buildsystems
cmake_minimum_required(VERSION 3.16)
# Name des Projekts
project(ProjectAlpha)

#----------------------------------------------#
#-------------------Optionen-------------------#
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
#---------------Erzeuge Projekt----------------#
#----------------------------------------------#

# Baue das Programm 'demo1' aus den Quellen
# examples/demo1.cpp und allen Quelldateien in
# SRC_FILES (also alle im Verzeichnis src/)
add_executable(demo
  examples/demo.cpp
  ${SRC_FILES}
)
