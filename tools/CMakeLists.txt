cmake_minimum_required(VERSION 2.8.11)

project(oconnells)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_bson_bind(${CMAKE_CURRENT_SOURCE_DIR}/../bson_binds/button_states.bsonbind BSON_BIND_INCLUDES)

add_executable(oconnells oconnells.cpp ${BSON_BIND_INCLUDES})
target_link_libraries(oconnells daylite bson-1.0)