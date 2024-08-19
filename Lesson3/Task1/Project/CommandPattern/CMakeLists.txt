cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN yes)
set(BUILD_SHARED_LIBS ON)
add_library(CommandPattern)
set_property(TARGET CommandPattern PROPERTY CXX_STANDARD 20)
set(headers ${CMAKE_CURRENT_SOURCE_DIR}/header/command_pattern.h)
set(sources ${CMAKE_CURRENT_SOURCE_DIR}/source/command_pattern.cpp)
list(APPEND ${sources} ${headers})
target_sources(CommandPattern PRIVATE ${sources})
target_include_directories(CommandPattern PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header)
if(BUILD_SHARED_LIBS)
target_compile_definitions(CommandPattern PUBLIC "USE_SHARED_LIB")
endif()

include(GenerateExportHeader)
if(BUILD_SHARED_LIBS)
set(export_file_name "export_shared.h")
else()
set(export_file_name "export_static.h")
endif()

generate_export_header(CommandPattern
EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/header/${export_file_name}
EXPORT_MACRO_NAME API_COMMAND_PATTERN
 )
 
list(APPEND ${sources} ${CMAKE_CURRENT_SOURCE_DIR}/header/${export_file_name})
install(TARGETS CommandPattern DESTINATION ${PROJECT_SOURCE_DIR}/install)