cmake_minimum_required (VERSION 3.15)

project (VitanShell)

aux_source_directory(. SRC_LIST)

if(NOT DEFINED BUILD_NUMBER)
    set(BUILD_NUMBER "unknown")
endif()

if(NOT DEFINED BUILD_DATE)
    set(BUILD_DATE "unknown")
endif()

add_executable(VitanShell ${SRC_LIST})

target_include_directories(VitanShell PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_compile_definitions(VitanShell PUBLIC
    BUILD_NUMBER="${BUILD_NUMBER}"
    BUILD_DATE="${BUILD_DATE}"
)
