cmake_minimum_required(VERSION 3.20)

project(DP_L3_T3 VERSION 1.0)
set(CMAKE_BUILD_TYPE Debug)
add_executable(main)

add_subdirectory(LogMessage)
#add_subdirectory(LogMessage/ErrorHandlers)
set_property(TARGET main PROPERTY CXX_STANDARD 20)
set(sources ${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp)
target_sources(main PUBLIC ${sources})


#target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/LogMessage)
#target_link_libraries(LogMessage PUBLIC LogMessage/ErrorHandlers)
target_link_libraries(main PUBLIC LogMessage)
install(TARGETS main DESTINATION ${PROJECT_SOURCE_DIR}/install)