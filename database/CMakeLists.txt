
cmake_minimum_required(VERSION 3.16)

target_sources(${TARGET_NAME} PRIVATE emoji.c)
target_sources(${TARGET_NAME} PRIVATE emoji.h)

target_sources(${TARGET_NAME} PRIVATE database.h)
target_sources(${TARGET_NAME} PRIVATE database.c)



