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

#include "database.h"

#ifdef __cplusplus
extern "C"
{
#endif

int  ec_epl_max_collumns    = -1;
int  ec_epl_max_rows        = -1;
BOOL ec_epl_auto_matrix     = false;
BOOL ec_epl_fill_matrix     = false;

ec_elp_profile *ec_elp_profiles = EC_NULL;

void ec_elp_reset_profile(ec_elp_profile *ptr)
{
    ec_elp_users index = (ec_elp_users)0;
    ptr->prevOBJ = EC_NULL;
    for(; index < ec_elp_user_max; index++)
    {
        ptr->user_profile[index].prefix[0]                = '\0';
        ptr->user_profile[index].prefix_text_weight       = Font_Weight_Normal;
        ptr->user_profile[index].prefix_text_color        = Color_Name_None;
        ptr->user_profile[index].text_weight              = Font_Weight_Normal;
        ptr->user_profile[index].text_color               = Color_Name_None;
        ptr->user_profile[index].suffix_text_weight       = Font_Weight_Normal;
        ptr->user_profile[index].suffix_text_color        = Color_Name_None;
        ptr->user_profile[index].prefix_background_weight = Font_Weight_Normal;
        ptr->user_profile[index].prefix_background_color  = Color_Name_None;
        ptr->user_profile[index].background_weight        = Font_Weight_Normal;
        ptr->user_profile[index].background_color         = Color_Name_None;
        ptr->user_profile[index].suffix_background_weight = Font_Weight_Normal;
        ptr->user_profile[index].suffix_background_color  = Color_Name_None;
        ptr->user_profile[index].suffix[0]                = '\0';
    }
    ptr->nextOBJ = EC_NULL;
}

void ec_elp_add_new_profile(string_t *profile_name)
{
    iterator_t(ec_elp_profile *) itr = ec_elp_profile_begin();
    iterator_t(ec_elp_profile *) prv = EC_NULL;
    while(iterator_value(itr) != EC_NULL)
    {
        prv = itr;
        itr = ec_elp_profile_next(itr);
        if(iterator_value(itr) != EC_NULL)
            iterator_value(prv)->nextOBJ = itr;
    }
        /*itr = (iterator_t(ec_elp_profile *))(&(iterator_value(itr)->nextOBJ));*/
    if(iterator_value(itr) == EC_NULL)
    {
        iterator_value(itr) = malloc(sizeof(ec_elp_profile));
        ec_elp_reset_profile(iterator_value(itr));
        strcpy(iterator_value(itr)->profile_name, profile_name);
        iterator_value(itr)->prevOBJ = prv;
        /**/
    }
}

#ifdef __cplusplus
}
#endif









