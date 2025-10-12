cmake_minimum_required(VERSION 3.25)

project(tp1)

set(SOURCE_FILES    main.cpp
                    utilitaire.cpp
                    lexique.cpp
                    sublexique.cpp)

add_executable(tp1 ${SOURCE_FILES})