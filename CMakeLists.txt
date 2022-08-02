
cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME               "Easy.Linux.Prompt")
set(PROJECT_NAME_USER_FRIENDLY "Easy Linux Prompt")
set(PROJECT_VERSION_STR        "1.0.0a")
set(TARGET_NAME  "ec-elp")

#compiler is free to be anything and any version

    #uncomment to select "GNU Compiler Collection" as your compiler
    #set(CMAKE_C_COMPILER            gcc)
    #set(COMPILER_IN_USE           "GCC")

    #uncomment to select "LLVM CLang C compiler" as your compiler
    set(CMAKE_C_COMPILER            clang)
    #set(COMPILER_IN_USE           "CLANG")

    #uncomment to select "Intel C Compiler" as your compiler
    #set(CMAKE_C_COMPILER            icc)
    #set(COMPILER_IN_USE           "ICC")

#set(CMAKE_C_STANDARD            89)
set(CMAKE_C_STANDARD_REQUIRED   ON)
set(CMAKE_C_EXTENSIONS          OFF)
set(CMAKE_GENERATOR 		"Ninja")
project(${PROJECT_NAME} LANGUAGES C)

# making sure the code as absolutely no undefined behaviour, can be compiled on
# any compiler out there, and never "stops working" because of an update to
# anything.
#
# Compile flags:
#       Optimization:     Level 3
#       Link model:       Static
#       C standard:       Ansi
#       Portability:      Pedantic
#       Warning level:    Warnings are errors
#       Enabled warnings: -Wall   = warning all
#                         -Wextra = extra warnings
#
# Other flags enable more warnings to prevent undefined behaviour.

add_compile_options("-O3")

add_compile_options("-static")

#add_compile_options("-ansi")
add_compile_options("-std=c89")
add_compile_options("-Wall")
add_compile_options("-Wextra")
add_compile_options("-pedantic")
add_compile_options("-Wpedantic")

add_compile_options("-Wundef")
add_compile_options("-Werror")
add_compile_options("-Wshadow")
add_compile_options("-Wcast-qual")
add_compile_options("-Wconversion")
add_compile_options("-Wfloat-equal")
add_compile_options("-Wswitch-enum")
add_compile_options("-Wunused-macros")
add_compile_options("-fstack-protector")
if(${COMPILER_IN_USE} MATCHES "GCC")
add_compile_options("-Wduplicated-cond")
add_compile_options("-Wduplicated-branches")
add_compile_options("-ftree-loop-vectorize")
add_compile_options("-Waggressive-loop-optimizations")
endif()

add_compile_options("-fPIC")
add_compile_options("-flto")

################################################################################

add_compile_options("-DSTRINGIZE(x)=#x")
add_compile_options("-DECAPI_PROJECT_NAME=STRINGIZE(${PROJECT_NAME_USER_FRIENDLY})")
add_compile_options("-DECAPI_PROJECT_VERSION=STRINGIZE(${PROJECT_VERSION_STR})")

################################################################################

add_link_options("-O3")

add_link_options("-static")

#add_link_options("-ansi")
add_compile_options("-std=c89")
add_link_options("-Wall")
add_link_options("-Wextra")
add_link_options("-pedantic")
add_link_options("-Wpedantic")

add_link_options("-Wundef")
add_link_options("-Werror")
add_link_options("-Wshadow")
add_link_options("-Wcast-qual")
add_link_options("-Wconversion")
add_link_options("-Wfloat-equal")
add_link_options("-Wswitch-enum")
add_link_options("-Wunused-macros")
add_link_options("-fstack-protector")
if(${COMPILER_IN_USE} MATCHES "GCC")
add_link_options("-Wduplicated-cond")
add_link_options("-ftree-loop-vectorize")
add_link_options("-Wduplicated-branches")
add_link_options("-Waggressive-loop-optimizations")
endif()

add_link_options("-fPIC")
add_link_options("-flto")

################################################################################

add_executable(${TARGET_NAME})

target_sources(${TARGET_NAME} PRIVATE main.c)


add_subdirectory(compiler.port)
add_subdirectory(POSIX)
add_subdirectory(Parse)
add_subdirectory(database)

