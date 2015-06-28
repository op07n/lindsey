cmake_minimum_required(VERSION 2.8.11)

project(lindsey)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

if(BITBAKE_BS)
  find_package(Qt5 COMPONENTS Network Widgets Qml)
else()
  find_package(Qt5 COMPONENTS Network WebEngine Widgets Qml)
endif()

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(RC_DIR ${CMAKE_SOURCE_DIR}/rc)

include_directories(${INCLUDE_DIR})

file(GLOB INCLUDES ${INCLUDE_DIR}/*.hpp)
file(GLOB SRCS ${SRC_DIR}/*.cpp)
file(GLOB RC ${RC_DIR}/*.qrc)

qt5_add_resources(SRCS ${RC})

add_executable(lindsey ${SRCS} ${INCLUDES} ${RC})
if(BITBAKE_BS)
  target_link_libraries(lindsey Qt5::Widgets Qt5::Qml qt5webengine)
else()
  target_link_libraries(lindsey Qt5::WebEngine Qt5::Widgets Qt5::Qml)
endif()
