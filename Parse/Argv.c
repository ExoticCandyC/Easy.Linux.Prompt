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

#include "Argv.h"
#include "../POSIX/Ansi_Sequences.h"
#include "../POSIX/POSIX.h"
#include <string.h>

#include "../database/database.h"

#ifdef __cplusplus
extern "C"
{
#endif


#define ____EPL_ARGV_LIST_TEMP(OPT1, OPT2, DESC, NAME) \
    OPT1,
const string_t *EPL_ARGV_Short_Options[] =
{
    __EPL_ARGV_LIST
    ""
};
#undef ____EPL_ARGV_LIST_TEMP

#define ____EPL_ARGV_LIST_TEMP(OPT1, OPT2, DESC, NAME) \
    OPT2,
const string_t *EPL_ARGV_Long_Options[] =
{
    __EPL_ARGV_LIST
    ""
};
#undef ____EPL_ARGV_LIST_TEMP

#define ____EPL_ARGV_LIST_TEMP(OPT1, OPT2, DESC, NAME) \
    DESC,
const string_t *EPL_ARGV_Descriptions[] =
{
    __EPL_ARGV_LIST
    color_text_red() "error: " color_reset() "unrecognized command-line option "
};
#undef ____EPL_ARGV_LIST_TEMP

#ifdef EXOTIC_CANDY_PRIVATE_API
weak
#endif
void ecapi_print_help(size_t opt_count,
                      const iterator_t(string_t *) long_opt,
                      const iterator_t(string_t *) short_opt,
                      const iterator_t(string_t *) descriptions)
{
    size_t index = 0;
    int    offset  = 29;
    int    max_len = ecio_terminal_columns() - offset - 1;
    printf("Usage: ec-elp [options]" end_line() "Options:" end_line());
    for(index = 0; index < opt_count; index++)
    {
        printf(printf_string(7) printf_string(-5) printf_string(-15), "",
                                             short_opt[index], long_opt[index]);
        ecio_print_confined_text(descriptions[index], offset, max_len);
    }
    printf(end_line()
           "For bug reporting instructions, please see:"
           end_line()
           "<https://github.com/ExoticCandyC/Easy.Linux.Prompt/issues>."
           end_line());
    exit(0);
}

#ifdef EXOTIC_CANDY_PRIVATE_API
weak
#endif
void ecapi_print_version()
{
    string_t date[] = __DATE__;
    iterator_t(string_t) year = date + strlen(date) - 4;
    printf("ec-elp (" ECAPI_PROJECT_NAME ") " ECAPI_PROJECT_VERSION end_line());
    printf("Copyright (C) " printf_string() " https://github.com/ExoticCandyC"
                             end_line(), year);
    ecio_print_confined_text("This is free software; see the source for copying"
                             " conditions. There is NO warranty; not even for "
                             "MERCHANTABILITY or FITNESS FOR A PARTICULAR "
                             "PURPOSE." end_line(), 0, ecio_terminal_columns());
    exit(0);
}

#ifdef EXOTIC_CANDY_PRIVATE_API
weak
#endif
size_t ecapi_parse_arg(string_t *argv, const iterator_t(string_t *) long_opt,
                       const iterator_t(string_t *) short_opt, size_t opt_count)
{
    size_t index = 0;
    for(index = 0; index < opt_count; index++)
    {
        if(strcmp(argv, short_opt[index]) == 0 ||
           strcmp(argv, long_opt [index]) == 0)
            return index;
    }
    return index;
}

#ifdef EXOTIC_CANDY_PRIVATE_API
weak
#endif
void ecapi_parse_argv(int argc, string_t *argv[])
{
    uint8_t  index;
    EPL_Argv argIndex;
    for(index = 1; index < (uint8_t)argc; index++)
    {
        argIndex = (EPL_Argv)ecapi_parse_arg(argv[index], EPL_ARGV_Long_Options,
                                  EPL_ARGV_Short_Options, (size_t)epl_argv_max);
        switch(argIndex)
        {
            case epl_argv_help:
                ecapi_print_help((size_t)epl_argv_max, EPL_ARGV_Long_Options,
                                                       EPL_ARGV_Short_Options,
                                                       EPL_ARGV_Descriptions);
                break;
            case epl_argv_version:
                ecapi_print_version();
                break;
            case epl_argv_config:
            case epl_argv_profile:
            case epl_argv_rows:
            case epl_argv_cols:
            case epl_argv_max:
            default:
                printf("ec-epl: " printf_string() "\"" printf_string() "\""
                       end_line(), EPL_ARGV_Descriptions[epl_argv_max],
                              argv[index]);
                exit(1);
                break;
        };
    }
}

#ifdef __cplusplus
}
#endif
