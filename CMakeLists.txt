cmake_minimum_required(VERSION 2.6)
project(Majic)

set(CMAKE_BUILD_TYPE Debug)

set(${PROJECT_NAME}_VERSION_MAJOR 0)
set(${PROJECT_NAME}_VERSION_MINOR 1)
set(${PROJECT_NAME}_VERSION_PATCH 0)

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=gnu++0x)
endif()

set(PROJECT_SOURCES
	src/string.cpp
  src/stream.cpp
  src/debugstream.cpp
  src/file.cpp
)

set(PROJECT_HEADERS
  src/string.hpp
  src/stream.hpp
  src/number.hpp
  src/file.hpp
  src/majic.hpp
  src/debugstream.hpp
)

source_group(Majic FILES ${PROJECT_SOURCES} ${PROJECT_HEADERS})

include_directories(${PROJECT_SOURCE_DIR})
add_library(majic STATIC ${PROJECT_SOURCES} ${PROJECT_HEADERS})

add_executable(test src/main.cpp)
target_link_libraries(test majic)
