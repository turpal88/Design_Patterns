cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN yes)
set(BUILD_SHARED_LIBS OFF)
add_library(Observer)
set_property(TARGET Observer PROPERTY CXX_STANDARD 20)
set(headers ${CMAKE_CURRENT_SOURCE_DIR}/header/observer.h)
set(sources ${CMAKE_CURRENT_SOURCE_DIR}/source/observer.cpp)
list(APPEND ${sources} ${headers})
target_sources(Observer PRIVATE ${sources})
target_include_directories(Observer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header)
if(BUILD_SHARED_LIBS)
target_compile_definitions(Observer PUBLIC "USE_SHARED_LIB")
endif()

include(GenerateExportHeader)
if(BUILD_SHARED_LIBS)
set(export_file_name "export_shared.h")
else()
set(export_file_name "export_static.h")
endif()

generate_export_header(Observer 
EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/header/${export_file_name}
EXPORT_MACRO_NAME API_OBSERVER
)

list(APPEND ${sources} ${CMAKE_CURRENT_SOURCE_DIR}/header/${export_file_name})
install(TARGETS Observer DESTINATION ${PROJECT_SOURCE_DIR}/install)