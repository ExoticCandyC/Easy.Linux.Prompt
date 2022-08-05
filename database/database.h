/**
 ** @copyright
 ** This file is part of the "Easy Linunx Prompt" project.
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
#include "../POSIX/Ansi_Sequences.h"

#ifdef __cplusplus
extern "C"
{
#endif

extern int  ec_epl_max_collumns;
extern int  ec_epl_max_rows;
extern BOOL ec_epl_auto_matrix;
extern BOOL ec_epl_fill_matrix;

typedef enum
{
    ec_elp_user_root,
    ec_elp_user_native,
    ec_elp_user_anonymous,
    ec_elp_user_unknown,
    ec_elp_user_max
} ec_elp_users;

typedef struct
{
    union
    {
        int       prefix_text_weight         : 1;
        int       prefix_text_color          : 4;
        int       text_weight                : 1;
        int       text_color                 : 4;
        int       suffix_text_weight         : 1;
        int       suffix_text_color          : 4;
        int       prefix_background_weight   : 1;
        int       prefix_background_color    : 4;
        int       background_weight          : 1;
        int       background_color           : 4;
        int       suffix_background_weight   : 1;
        int       suffix_background_color    : 4;
        string_t  prefix[0xFF];
        string_t  suffix[0xFF];
    } user_profile[ec_elp_user_max];
    string_t  profile_name[0xFF];
    void     *nextOBJ;
    void     *prevOBJ;
} ec_elp_profile;

typedef ec_elp_profile *profile_iterator;

extern  iterator_t(ec_elp_profile) ec_elp_profiles;

#define ec_elp_profile_begin()          &ec_elp_profiles
#define ec_elp_profile_end()            EC_NULL
#define ec_elp_profile_next(itr)        ((iterator_t(ec_elp_profile *))(&(iterator_value(itr)->nextOBJ)))
#define ec_elp_profile_previous(itr)    ((iterator_t(ec_elp_profile *))(&(iterator_value(itr)->prevOBJ)))

void ec_elp_reset_profile(ec_elp_profile *ptr);

void ec_elp_add_new_profile(string_t *profile_name);

#ifdef __cplusplus
}
#endif





