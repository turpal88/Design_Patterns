cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN yes)
set(BUILD_SHARED_LIBS ON)
add_library(LogMessage)
set_property(TARGET LogMessage PROPERTY CXX_STANDARD 20)

#add_subdirectory(ErrorHandlers)
set(headers ${CMAKE_CURRENT_SOURCE_DIR}/header/log_message.h ${CMAKE_CURRENT_SOURCE_DIR}/header/export.h)
set(sources ${CMAKE_CURRENT_SOURCE_DIR}/source/log_message.cpp)
list(APPEND ${sources} ${headers})
target_sources(LogMessage PUBLIC ${sources})


if(BUILD_SHARED_LIBS)
target_compile_definitions(LogMessage PRIVATE "USE_SHARED_LIB")
set(export_file_name "export_shared.h")
else()
set(export_file_name "export_static.h")
endif()

target_include_directories(LogMessage PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header ${PROJECT_SOURCE_DIR}/ErrorHandlers/header)
target_link_libraries(LogMessage PUBLIC ErrorHandlers)

include(GenerateExportHeader)
generate_export_header(LogMessage
EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/header/${export_file_name}
EXPORT_MACRO_NAME API_LOG_MESSAGE
)
list(APPEND ${sources} ${CMAKE_CURRENT_SOURCE_DIR}/header/${export_file_name})
install(TARGETS LogMessage DESTINATION ${PROJECT_SOURCE_DIR}/install)