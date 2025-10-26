cmake_minimum_required (VERSION 3.15)

project (VitanShell)

aux_source_directory(. SRC_LIST)

add_executable(VitanShell ${SRC_LIST})