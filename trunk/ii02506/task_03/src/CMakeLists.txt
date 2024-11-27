cmake_minimum_required(VERSION 3.5)

project(otis_3)

set(SOURCES
    Source.cpp
    ConsoleApplication1.cpp
)

set(HEADERS
    Header.h
)

add_executable(OTIS_03 ${SOURCES} ${HEADERS})