cmake_minimum_required(VERSION 3.20)


project(DP_L2_T1 VERSION 1.0)
set(CMAKE_BUILD_TYPE Debug)
add_executable(main)
add_subdirectory(Decorator)

set_property(TARGET main PROPERTY CXX_STANDARD 20)
set(sources ${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp)
target_sources(main PRIVATE ${sources})
target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/Decorator/headers)
target_link_libraries(main PRIVATE Decorator)
install(TARGETS main DESTINATION ${PROJECT_SOURCE_DIR}/install)