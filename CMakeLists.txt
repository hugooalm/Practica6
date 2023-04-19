cmake_minimum_required(VERSION 3.22)
project(ejemplo_sqlite_c C)

set(CMAKE_C_STANDARD 99)

add_executable(ejemplo_sqlite_c sqlite3.c sqlite3.h main.c)
