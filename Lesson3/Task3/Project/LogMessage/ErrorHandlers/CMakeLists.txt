cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN yes)
set(BUILD_SHARED_LIBS ON)
add_library(ErrorHandlers)
set_property(TARGET ErrorHandlers PROPERTY CXX_STANDARD 20)

set(headers ${CMAKE_CURRENT_SOURCE_DIR}/header/error_handler.h ${CMAKE_CURRENT_SOURCE_DIR}/header/export.h)
set(sources ${CMAKE_CURRENT_SOURCE_DIR}/source/error_handler.cpp)
list(APPEND ${sources} ${headers})
target_sources(ErrorHandlers PUBLIC ${sources})


target_include_directories(ErrorHandlers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header)
if(BUILD_SHARED_LIBS)
target_compile_definitions(ErrorHandlers PRIVATE "USE_SHARED_LIB")
set(export_file_name "export_shared.h")
else()
set(export_file_name "export_static.h")
endif()

include(GenerateExportHeader)
generate_export_header(ErrorHandlers
EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/header/${export_file_name}
EXPORT_MACRO_NAME API_ERROR_HANDLERS
)

list(APPEND ${sources} ${CMAKE_CURRENT_SOURCE_DIR}/header/${export_file_name})
install(TARGETS ErrorHandlers DESTINATION ${PROJECT_SOURCE_DIR}/install)

