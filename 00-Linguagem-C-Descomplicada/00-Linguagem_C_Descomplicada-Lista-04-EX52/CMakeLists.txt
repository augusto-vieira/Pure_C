cmake_minimum_required (VERSION 3.09)

project(app)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Debug)

add_executable(app "")
target_sources(app
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/main.c 
  )
install(TARGETS app DESTINATION bin)

