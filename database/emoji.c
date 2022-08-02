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

#include "emoji.h"
#include <time.h>

#ifdef __cplusplus
extern "C"
{
#endif

void ec_elp_time_analogue_clock(stime_t time, emoji_t ptr)
{
    string_t *clocks[] = {emoji_clocks};
    time.tm_hour *= 2;

    if(time.tm_min <= 45 && time.tm_min >= 15)
        time.tm_hour += 1;
    else if(time.tm_min >  45)
        time.tm_hour += 2;

    time.tm_hour = time.tm_hour % 24;

    emojicpy(ptr, clocks[time.tm_hour]);
}


#ifdef __cplusplus
}
#endif
