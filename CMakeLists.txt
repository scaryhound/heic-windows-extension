cmake_minimum_required(VERSION 3.15)

project(HeicWindowsExtension CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(libheif CONFIG REQUIRED)

set(SOURCES src/HeicDecoder.cpp )

add_library(HeicDecoder SHARED ${SOURCES})

target_link_libraries(HeicDecoder PRIVATE heif)

if(WIN32)
	target_link_libraries(HeicDecoder PRIVATE ole32 oleaut32 windowscodecs uuid)
	set_target_properties(HeicDecoder PROPERTIES 
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
    LINK_FLAGS "/NODEFAULTLIB:MSVCRT /NODEFAULTLIB:MSVCPRT /FORCE:MULTIPLE"
)
endif()

set_target_properties(HeicDecoder PROPERTIES SUFFIX ".dll")
