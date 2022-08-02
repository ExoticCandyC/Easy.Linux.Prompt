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

#ifdef __cplusplus
extern "C"
{
#endif

#define emoji_size   sizeof("💖️")

typedef string_t emoji_t[emoji_size];

#define utf_flower_1          "✿"
#define utf_flower_2          "❁"
#define utf_star              "☆"

#define utf_three_dots        "…"
#define utf_three_dots_mid    "⋯"

#define emoji_candy           "🍭️"
#define emoji_candy2          "🍬️"
#define emoji_sweat_smile     "😅️"
#define emoji_hug             "🤗️"
#define emoji_hand_over_mouth "🤭️"
#define emoji_kiss_heart      "😘️"
#define emoji_weird_face      "🥴️"
#define emoji_mouse           "🐁️"
#define emoji_sleeping        "😴️"
#define emoji_head_explode    "🤯️"
#define emoji_scream          "😱️"
#define emoji_sparkling_heart "💖️"
#define emoji_thought_bubble  "💭️"
#define emoji_rose            "🌹️"

#define emoji_clocks "🕛️", "🕧️", "🕐️", "🕜️", "🕑️", "🕝️", "🕒️", "🕞️", \
                     "🕓️", "🕟️", "🕔️", "🕠️", "🕕️", "🕡️", "🕖️", "🕢️", \
                     "🕗️", "🕣️", "🕘️", "🕤️", "🕙️", "🕥️", "🕚️", "🕦️"

#define emojicpy(DST, SRC) strncpy(DST, SRC, emoji_size);

void ec_elp_time_analogue_clock(stime_t time, emoji_t ptr);

#define ec_elp_analogue_clock_now(ptr)  \
            { \
                stime_t ____now = ecio_time_now(); \
                ec_elp_time_analogue_clock(____now, ptr); \
            }

#ifdef __cplusplus
}
#endif
