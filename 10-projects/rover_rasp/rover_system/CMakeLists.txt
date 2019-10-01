cmake_minimum_required(VERSION 3.7.0)

project(rasp_rover)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

# This one is important
SET(CMAKE_SYSTEM_NAME Linux)

# Specify the cross compiler
#SET(CMAKE_C_COMPILER   arm-linux-gnueabihf-gcc)
#SET(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)

function(add_test_unit BIN_NAME BIN SOURCE)
  add_executable(${BIN} ${SOURCE})
  set_target_properties(${BIN}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/tests
    )
    add_test(NAME ${BIN_NAME} COMMAND ${BIN})
endfunction()

enable_testing()

#------------------------------------------------------------------------------------------------------
#lib utils
#------------------------------------------------------------------------------------------------------
add_library(utils "")

target_link_libraries(utils PUBLIC pthread rt)
target_sources(utils
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/lib/src/queue.c
  ${CMAKE_CURRENT_LIST_DIR}/lib/src/shared_memory.c
  ${CMAKE_CURRENT_LIST_DIR}/lib/src/sema.c
  ${CMAKE_CURRENT_LIST_DIR}/lib/src/log.c
  ${CMAKE_CURRENT_LIST_DIR}/lib/src/file.c
  )

target_include_directories(utils
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  ${CMAKE_CURRENT_LIST_DIR}/include
  )

#------------------------------------------------------------------------------------------------------
#lib drivers
#------------------------------------------------------------------------------------------------------
add_library(drivers "")
target_link_libraries(drivers PUBLIC wiringPi)
target_sources(drivers 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/driver/src/hc_sr04.c
  ${CMAKE_CURRENT_LIST_DIR}/driver/src/motors.c
  ${CMAKE_CURRENT_LIST_DIR}/driver/src/servo.c
  ${CMAKE_CURRENT_LIST_DIR}/driver/src/servo_action.c
  )

target_include_directories(drivers 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/driver/include
  )

#------------------------------------------------------------------------------------------------------
#rover_server 
#------------------------------------------------------------------------------------------------------
add_executable(rover_server "")
target_link_libraries(rover_server PUBLIC util utils)
#target_include_directories(lib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/lib/include)
target_sources(rover_server
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/src/rover_server.c
  )
target_include_directories(rover_server 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/include
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  )
install(TARGETS rover_server DESTINATION bin)

#------------------------------------------------------------------------------------------------------
#rover_client
#------------------------------------------------------------------------------------------------------
add_executable(rover_client "")
#target_link_libraries(client PUBLIC lib)
#target_include_directories(lib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/lib/include)
target_sources(rover_client
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/src/rover_client.c
  )
install(TARGETS rover_client DESTINATION bin)

#------------------------------------------------------------------------------------------------------
#rover_manager
#------------------------------------------------------------------------------------------------------
add_executable(rover_manager "")
target_link_libraries(rover_manager PUBLIC utils)
#target_include_directories(lib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/lib/include)
target_sources(rover_manager
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/src/rover_manager.c
  )
target_include_directories(rover_manager
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  ${CMAKE_CURRENT_LIST_DIR}/include
  )
install(TARGETS rover_manager DESTINATION bin)

#------------------------------------------------------------------------------------------------------
#rover_motor_control
#------------------------------------------------------------------------------------------------------
add_executable(rover_motor_control "")
target_link_libraries(rover_motor_control PUBLIC utils)
#target_include_directories(lib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/lib/include)
target_sources(rover_motor_control
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/src/rover_motor_control.c
  )
target_include_directories(rover_motor_control
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  )
install(TARGETS rover_motor_control DESTINATION bin)

#rover_servo_control
add_executable(rover_servo_control "")
target_link_libraries(rover_servo_control PUBLIC utils drivers)
#target_include_directories(lib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/lib/include)
target_sources(rover_servo_control
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/src/rover_servo_control.c
  )
target_include_directories(rover_servo_control
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  ${CMAKE_CURRENT_LIST_DIR}/driver/include
  )
install(TARGETS rover_servo_control DESTINATION bin)

#rover_launch
add_executable(rover_launch "")
target_link_libraries(rover_launch PUBLIC utils)
target_sources(rover_launch
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/src/rover_launch.c
  )
target_include_directories(rover_launch
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  )
install(TARGETS rover_launch DESTINATION bin)

#------------------------------------------------------------------------------------------------------
#rover_unlaunch
#------------------------------------------------------------------------------------------------------
add_executable(rover_unlaunch "")
target_link_libraries(rover_unlaunch PUBLIC utils)
target_sources(rover_unlaunch
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/src/rover_unlaunch.c
  )
target_include_directories(rover_unlaunch
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  )
install(TARGETS rover_unlaunch DESTINATION bin)

#------------------------------------------------------------------------------------------------------
#Tests
#------------------------------------------------------------------------------------------------------
add_test_unit(servo test_servo tests/test_servo.c)
target_link_libraries(test_servo PUBLIC drivers)

add_test_unit(motors test_motors tests/test_motors.c)
target_link_libraries(test_motors PUBLIC drivers)

add_test_unit(ultrasonic test_ultrasonic tests/test_ultrasonic.c)
target_link_libraries(test_ultrasonic PUBLIC drivers)

#------------------------------------------------------------------------------------------------------
#create a .deb file
#------------------------------------------------------------------------------------------------------
set(CPACK_PACKAGE_DESCRIPTION "Rover package")
set(CPACK_PACKAGE_VERSION_MAJOR "${VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${VERSION_PATCH}")
set(CPACK_PACKAGE_VENDOR "Solid Company")
set(CPACK_PACKAGE_CONTACT "support@acme.corp")
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
include (CPack)
