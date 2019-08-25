cmake_minimum_required(VERSION 3.9.0)

project(rasp_rover)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

# This one is important
SET(CMAKE_SYSTEM_NAME Linux)

# Specify the cross compiler
#SET(CMAKE_C_COMPILER   arm-linux-gnueabihf-gcc)
#SET(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)

set (CMAKE_C_FLAGS "-Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)

add_library(util "")

target_sources(util 
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/src/motors.c
  ${CMAKE_CURRENT_LIST_DIR}/src/actions.c
  )

target_include_directories(util PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

add_library(utils "")

target_sources(utils
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/lib/src/queue.c
  ${CMAKE_CURRENT_LIST_DIR}/lib/src/shared_memory.c
  )

target_include_directories(utils PUBLIC ${CMAKE_CURRENT_LIST_DIR}/lib/include)

#server 
add_executable(server "")
target_link_libraries(server PUBLIC util utils)
#target_include_directories(lib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/lib/include)
target_sources(server
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/server.c
  )
target_include_directories(server 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/include
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
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

#manager
add_executable(manager "")
target_link_libraries(manager PUBLIC utils)
#target_include_directories(lib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/lib/include)
target_sources(manager
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/manager.c
  )
target_include_directories(manager
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  )
install(TARGETS manager DESTINATION bin)

#manager
add_executable(motor_control "")
target_link_libraries(motor_control PUBLIC utils)
#target_include_directories(lib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/lib/include)
target_sources(motor_control
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/motor_control.c
  )
target_include_directories(motor_control
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  )
install(TARGETS motor_control DESTINATION bin)

#create a .deb file
set(CPACK_PACKAGE_DESCRIPTION "Rover package")
set(CPACK_PACKAGE_VERSION_MAJOR "${VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${VERSION_PATCH}")
set(CPACK_PACKAGE_VENDOR "Solid Company")
set(CPACK_PACKAGE_CONTACT "support@acme.corp")
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
include (CPack)
