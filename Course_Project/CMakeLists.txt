# CMakeList.txt: проект CMake для Course_Project; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Course_Project
"Course_Project.cpp"
"Course_Project.h"
"Enums.h"
"Interface.cpp"
"Interface.h"
"TaskExecution.cpp"
"TaskExecution.h"
"BinaryTree.h"
"DataBase.h"
"DataBase.cpp"
"TaskExecution.hpp"
"BinaryTree.cpp"
"Node.h"
"Node.cpp"
 "Interface.hpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
