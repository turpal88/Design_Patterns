cmake_minimum_required(VERSION 3.21)


#project(DP_L4_T2 VERSION 1.0)
#set(CMAKE_CXX_VISIBILITY_PRESET hidden)
#set(CMAKE_VISIBILITY_INLINES_HIDDEN yes)
#set(BUILD_SHARED_LIBS ON)
add_library(PrintSave INTERFACE)
set_property(TARGET PrintSave PROPERTY CXX_STANDARD 20)
set(sources ${CMAKE_CURRENT_SOURCE_DIR}/source/print_save.h)
target_sources(PrintSave PRIVATE ${sources})

#if(BUILD_SHARED_LIBS)
#target_compile_definitions(PrintSave PRIVATE "PRINT_SAVE_USE_SHARED_LIB")
#set(export_file_name "print_save_export_shared.h")
#else()
#set(export_file_name "print_save_export_static.h")
#endif()

target_include_directories(PrintSave INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/source)

#include(GenerateExportHeader)
#generate_export_header(PrintSave
#EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/source/${export_file_name}
#EXPORT_MACRO_NAME API_PRINT_SAVE
#)
#list(APPEND ${sources} ${CMAKE_CURRENT_SOURCE_DIR}/source/${export_file_name})
#install(TARGETS PrintSave DESTINATION ${PROJECT_SOURCE_DIR}/install)
