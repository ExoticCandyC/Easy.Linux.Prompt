
################################################################################
# CMake pre requirements - It cant be higher than the minimum required by ESP
# IDF, because then it would cause erros during cmake process in some cases.
################################################################################
cmake_minimum_required(VERSION 3.16)

################################################################################
# Setting up the versioning system and internal variables
################################################################################
set(Developement 0)
set(Nightly      1)
set(Alpha        2)
set(Beta         3)
set(Release      4)

set(EC_PROJECT_NAME         "Easy.Linux.Prompt")
set(EC_PROJECT_VERSION      1.0.0.${Developement})
set(EC_PROJECT_HOMEPAGE_URL "https://github.com/ExoticCandyC/Easy.Linux.Prompt")
set(EC_PROJECT_DESCRIPTION  "Linux prompt helper, brought to you by " /
    "https://github.com/ExoticCandyC")

################################################################################
# Creating the CMake Project
################################################################################
project(          ${EC_PROJECT_NAME}
    VERSION       ${EC_PROJECT_VERSION}
    HOMEPAGE_URL "${EC_PROJECT_HOMEPAGE_URL}"
    DESCRIPTION  "${EC_PROJECT_DESCRIPTION}"
    LANGUAGES C
)

################################################################################
# Setting up a navigator variable
################################################################################
set(ENV{EC_ELP_MAIN_CMAKE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

################################################################################
# Defining the modules used to add files
################################################################################
macro(EC_ELP_ADD_SOURCE_FILE)
    file(
        RELATIVE_PATH
        _relPath
        $ENV{EC_ELP_MAIN_CMAKE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
    )
if (_relPath)
    list (APPEND EC_ELP_SOURCE_FILES "${_relPath}/${ARGV0}")
else()
    list (APPEND EC_ELP_SOURCE_FILES "${ARGV0}")
endif()
set (EC_ELP_SOURCE_FILES ${EC_ELP_SOURCE_FILES} PARENT_SCOPE)
endmacro()

macro(EC_ELP_ADD_HEADER_FILE)
    file(
        RELATIVE_PATH
        _relPath
        $ENV{EC_ELP_MAIN_CMAKE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
    )
if (_relPath)
    list (APPEND EC_ELP_HEADER_FILES "${_relPath}/${ARGV0}")
else()
    list (APPEND EC_ELP_HEADER_FILES "${ARGV0}")
endif()
set (EC_ELP_HEADER_FILES ${EC_ELP_HEADER_FILES} PARENT_SCOPE)
endmacro()

macro (EXOTIC_CANDY_SYNC_FILES_WITH_PARENT)
    set (EC_ELP_SOURCE_FILES ${EC_ELP_SOURCE_FILES} PARENT_SCOPE)
    set (EC_ELP_HEADER_FILES ${EC_ELP_HEADER_FILES} PARENT_SCOPE)
endmacro()

################################################################################
# Adding sub directories
################################################################################
add_subdirectory(src)

################################################################################
# Setting general compile options
################################################################################
add_compile_options(-lm)
add_compile_options(-leclibc)
add_compile_options(-std=c99)
add_compile_options(-Werror)
add_compile_options(-Wall)
add_compile_options(-Wextra)
add_compile_options(-Wfloat-equal)
add_compile_options(-Wshadow)
add_compile_options(-Wswitch-enum)
add_compile_options(-Wcast-qual)
add_compile_options(-Wconversion)
add_compile_options(-Wundef)
add_compile_options(-Wunused-macros)
add_compile_options(-Wno-strict-aliasing)
add_compile_options(-Wduplicated-cond)
add_compile_options(-Wduplicated-branches)
add_compile_options(-Wno-variadic-macros)
add_compile_options(-pedantic)
add_compile_options(-Wpedantic)
add_compile_options(-fPIC)
add_compile_options(-Ofast)
add_compile_options(-fstack-protector)
add_compile_options(-flto)
add_compile_options(-ftree-loop-vectorize)
add_compile_options(-Waggressive-loop-optimizations)

################################################################################
# Setting general link options
################################################################################
add_link_options(-lm)
add_link_options(-leclibc)
add_link_options(-std=c99)
add_link_options(-Werror)
add_link_options(-Wall)
add_link_options(-Wextra)
add_link_options(-Wfloat-equal)
add_link_options(-Wshadow)
add_link_options(-Wswitch-enum)
add_link_options(-Wcast-qual)
add_link_options(-Wconversion)
add_link_options(-Wundef)
add_link_options(-Wunused-macros)
add_link_options(-Wno-strict-aliasing)
add_link_options(-Wduplicated-cond)
add_link_options(-Wduplicated-branches)
add_link_options(-pedantic)
add_link_options(-fPIC)
add_link_options(-Ofast)
add_link_options(-fstack-protector)
add_link_options(-flto)
add_link_options(-ftree-loop-vectorize)
add_link_options(-Waggressive-loop-optimizations)

################################################################################

set(TARGET_NAME  "ec-elp")
set(CMAKE_C_COMPILER gcc)

add_executable(${TARGET_NAME})

target_sources(
                  ${TARGET_NAME}
                  PRIVATE
                  ${EC_ELP_SOURCE_FILES}
                  ${EC_ELP_HEADER_FILES}
              )
