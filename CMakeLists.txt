cmake_minimum_required(VERSION 2.8.11)

project(lindsey)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR})
include(macros)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

if(BITBAKE_BS)
  find_package(Qt5 COMPONENTS Widgets Qml)
else()
  find_package(Qt5 COMPONENTS WebEngine Widgets Qml)
endif()

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(RC_DIR ${CMAKE_SOURCE_DIR}/rc)

include_directories(${INCLUDE_DIR})
if(APPLE)
  include_directories("/usr/local/include/libbson-1.0")
endif()

file(GLOB INCLUDES ${INCLUDE_DIR}/*.hpp)
file(GLOB SRCS ${SRC_DIR}/*.cpp)
file(GLOB RC ${RC_DIR}/*.qrc)

qt5_add_resources(SRCS ${RC})

add_bson_bind(${CMAKE_CURRENT_SOURCE_DIR}/bson_binds/button_states.bsonbind BSON_BIND_INCLUDES)

add_executable(lindsey ${SRCS} ${INCLUDES} ${BSON_BIND_INCLUDES} ${RC})
if(BITBAKE_BS)
  target_link_libraries(lindsey Qt5::Widgets Qt5::Qml Qt5WebEngine daylite bson-1.0)
else()
  target_link_libraries(lindsey Qt5::WebEngine Qt5::Widgets Qt5::Qml daylite bson-1.0)
endif()

add_subdirectory(tools)
