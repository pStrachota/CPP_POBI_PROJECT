cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
        src/math_helpers.cpp
        include/model/Client.h src/model/Client.cpp)
#utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES} include/model/Client.h src/model/Client.cpp)

target_include_directories(Library PUBLIC include)