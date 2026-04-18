cmake_minimum_required(VERSION 3.15)

project(HeicWindowsExtension CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(libheif CONFIG REQUIRED)

set(SOURCES src/HeicDecoder.cpp)

if(WIN32)
	list(APPEND SOURCES src/dllmain.cpp src/exports.def)
endif()

add_library(HeicDecoder SHARED ${SOURCES})

target_link_libraries(HeicDecoder PRIVATE heif)
