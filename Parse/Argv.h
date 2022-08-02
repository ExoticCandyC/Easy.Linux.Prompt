/**
 ** @copyright
 ** This file is part of the "Easy Linux Prompt" project.
 ** Copyright (C) 2022 ExoticCandy
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/


#pragma once

#include "../compiler.port/Data_Types.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define __EPL_ARGV_LIST \
    ____EPL_ARGV_LIST_TEMP("-h", "--help"   , "Display available options.",    \
                                                                 argv_help   ) \
    ____EPL_ARGV_LIST_TEMP("-v", "--version", "Print version information.",    \
                                                                 argv_version) \
    ____EPL_ARGV_LIST_TEMP("-c", "--config" , "Specifies the config file.",    \
                                                                 argv_config ) \
    ____EPL_ARGV_LIST_TEMP("-p", "--profile", "Specifies the profile to use, " \
                                              "regardless of the conditions "  \
                                              "defined in the config file.",   \
                                                                 argv_profile) \
    ____EPL_ARGV_LIST_TEMP("-r", "--rows"   , "Manually specify the number of "\
                                              "rows each prompt will take.",   \
                                                                 argv_rows   ) \
    ____EPL_ARGV_LIST_TEMP("-c", "--cols"   , "Manually specify the number of "\
                                              "columns each prompt will take.",\
                                                                 argv_cols   ) \
    /*
    ____EPL_ARGV_LIST_TEMP("-s", "--setup"  , "Runs the CLI configuration "
                                              "interface", argv_setup) \ */

#define ____EPL_ARGV_LIST_TEMP(OPT1, OPT2, DESC, NAME) \
    epl_##NAME,
typedef enum
{
    __EPL_ARGV_LIST
    epl_argv_max
} EPL_Argv;
#undef ____EPL_ARGV_LIST_TEMP

void ecapi_parse_argv(int argc, string_t *argv[]);

#ifdef __cplusplus
}
#endif
