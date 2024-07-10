cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN yes)
#set(BUILD_SHARED_LIBS OFF)
set(BUILD_SHARED_LIBS ON)
add_library(SqlQueryBuilderInherit)
set_property(TARGET SqlQueryBuilderInherit PROPERTY CXX_STANDARD 20)
set(headers ${CMAKE_CURRENT_SOURCE_DIR}/headers/sql_query_builder_inherit.h)
set(sources "sources/sql_query_builder.cpp")
list(APPEND ${sources} ${headers})
target_sources(SqlQueryBuilderInherit PRIVATE ${sources})
#add_subdirectory(SafeQueue)
target_include_directories(SqlQueryBuilderInherit PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)
#target_link_libraries(ThreadPool PRIVATE SafeQueue)

if(BUILD_SHARED_LIBS)
target_compile_definitions(SqlQueryBuilderInherit PUBLIC "USE_SHARED_LIB")
endif()

include(GenerateExportHeader)
if(BUILD_SHARED_LIBS)
set(export_file_name "export_shared.h")
else()

    set(export_file_name "export_static.h")
endif()

generate_export_header(SqlQueryBuilderInherit
EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/headers/${export_file_name}
EXPORT_MACRO_NAME API_SQL_QUERY_BUILDER

)

list(APPEND ${sources} ${CMAKE_CURRENT_SOURCE_DIR}/headers/${export_file_name})
install(TARGETS SqlQueryBuilderInherit DESTINATION ${PROJECT_SOURCE_DIR}/install)