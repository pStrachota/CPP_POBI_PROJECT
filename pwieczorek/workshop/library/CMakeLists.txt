cmake_minimum_required(VERSION 3.4)
project(library)

set(SOURCE_FILES
        src/math_helpers.cpp
        )
#Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(library ${SOURCE_FILES})

target_include_directories(library PUBLIC include)
