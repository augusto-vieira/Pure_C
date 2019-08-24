cmake_minimum_required(VERSION 3.9.0)

project(server_socket)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

set (CMAKE_C_FLAGS "-Wall -std=c99")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)


#server 
add_executable(server1 "")
target_sources(server1
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/server1.c
  )
target_include_directories(server1
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}
  )
install(TARGETS server1 DESTINATION bin)

#client
add_executable(client1 "")
target_sources(client1
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/client1.c
  )
target_include_directories(client1
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}
  )
install(TARGETS client1 DESTINATION bin)
