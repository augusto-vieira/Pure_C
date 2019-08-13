cmake_minimum_required(VERSION 3.9.0)

project(rasp_rover)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)

#add_library(lib "")
#
#target_sources(lib 
#  PUBLIC
#  ${CMAKE_CURRENT_LIST_DIR}/lib/src/pqueue.c
#  ${CMAKE_CURRENT_LIST_DIR}/lib/src/people.c
#  ${CMAKE_CURRENT_LIST_DIR}/lib/src/data.c
#  )
#target_include_directories(lib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/lib/include)

#server 
add_executable(server "")
#target_link_libraries(queue_writer PUBLIC lib)
#target_include_directories(lib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/lib/include)
target_sources(server
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/server.c
  )
install(TARGETS server DESTINATION bin)

#client
add_executable(client "")
#target_link_libraries(client PUBLIC lib)
#target_include_directories(lib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/lib/include)
target_sources(client
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/client.c
  )
install(TARGETS client DESTINATION bin)

#create a .deb file

