cmake_minimum_required(VERSION 3.20)


set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN yes)



#set(BUILD_SHARED_LIBS OFF)
set(BUILD_SHARED_LIBS OFF)
add_library(VeryHeavyDB)
set_property(TARGET VeryHeavyDB PROPERTY CXX_STANDARD 20)
set(headers ${CMAKE_CURRENT_SOURCE_DIR}/headers/veryheavydb.h)
set(sources ${CMAKE_CURRENT_SOURCE_DIR}/sources/veryheavydb.cpp)
list(APPEND ${sources} ${headers})
target_sources(VeryHeavyDB PRIVATE ${sources})
#add_subdirectory(SafeQueue)
target_include_directories(VeryHeavyDB PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)
#target_link_libraries(ThreadPool PRIVATE SafeQueue)

if(BUILD_SHARED_LIBS)
target_compile_definitions(VeryHeavyDB PUBLIC "USE_SHARED_LIB")
endif()

include(GenerateExportHeader)
if(BUILD_SHARED_LIBS)
set(export_file_name "export_shared.h")
else()

    set(export_file_name "export_static.h")
endif()

generate_export_header(VeryHeavyDB
EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/headers/${export_file_name}
EXPORT_MACRO_NAME API_VERYHEAVYDB

)

list(APPEND ${sources} ${CMAKE_CURRENT_SOURCE_DIR}/headers/${export_file_name})
install(TARGETS VeryHeavyDB DESTINATION ${PROJECT_SOURCE_DIR}/install)