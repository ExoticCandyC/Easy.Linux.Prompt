
cmake_minimum_required(VERSION 3.16)

target_sources(${TARGET_NAME} PRIVATE POSIX.c)
target_sources(${TARGET_NAME} PRIVATE POSIX.h)
target_sources(${TARGET_NAME} PRIVATE Ansi_Sequences.h)


