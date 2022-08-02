
#pragma once

#ifndef EXOTIC_CANDY_PRIVATE_API

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdlib.h>
#include "../compiler.port/Data_Types.h"

#define cursor_goto(x, y)            "\033[" #y ";" #x "H"
#define cursor_goto_variable()       "\033[" printf_uint8(1,1) ";" printf_uint8(1,1) "H"

#define cursor_goto_expand(x, y)     y, x

#define cursor_move_up(N)            "\033[" #N "A"
#define cursor_move_down(N)          "\033[" #N "B"
#define cursor_move_right(N)         "\033[" #N "C"
#define cursor_move_left(N)          "\033[" #N "D"

#define cursor_move_up_variable()    "\033[" printf_uint8(1,1) "A"
#define cursor_move_down_variable()  "\033[" printf_uint8(1,1) "B"
#define cursor_move_right_variable() "\033[" printf_uint8(1,1) "C"
#define cursor_move_left_variable()  "\033[" printf_uint8(1,1) "D"

#define clear_screen()               "\033[2J" cursor_goto(0,0)

#define cursor_home()                "\r"
#define cursor_clear_line()          cursor_home() "\033[K"

#define cursor_save()                "\033[s"
#define cursor_restore()             "\033[u"

#define end_line()                   cursor_home() "\n"
#define new_line()                   cursor_home() "\n"

#define color_reset()                "\x1B[0m"

#define color_text_black()           "\x1B[30m"
#define color_text_red()             "\x1B[31m"
#define color_text_green()           "\x1B[32m"
#define color_text_yellow()          "\x1B[33m"
#define color_text_blue()            "\x1B[34m"
#define color_text_magenta()         "\x1B[35m"
#define color_text_cyan()            "\x1B[36m"
#define color_text_white()           "\x1B[37m"

#define color_text_light_black()     "\x1B[90m"
#define color_text_light_red()       "\x1B[91m"
#define color_text_light_green()     "\x1B[92m"
#define color_text_light_yellow()    "\x1B[93m"
#define color_text_light_blue()      "\x1B[94m"
#define color_text_light_magenta()   "\x1B[95m"
#define color_text_light_cyan()      "\x1B[96m"
#define color_text_light_white()     "\x1B[97m"

#define color_bg_black()             "\x1B[100m"
#define color_bg_red()               "\x1B[101m"
#define color_bg_green()             "\x1B[102m"
#define color_bg_yellow()            "\x1B[103m"
#define color_bg_blue()              "\x1B[104m"
#define color_bg_magenta()           "\x1B[105m"
#define color_bg_cyan()              "\x1B[106m"
#define color_bg_white()             "\x1B[107m"

#define color_bg_light_black()       "\x1B[40m"
#define color_bg_light_red()         "\x1B[41m"
#define color_bg_light_green()       "\x1B[42m"
#define color_bg_light_yellow()      "\x1B[43m"
#define color_bg_light_blue()        "\x1B[44m"
#define color_bg_light_magenta()     "\x1B[45m"
#define color_bg_light_cyan()        "\x1B[46m"
#define color_bg_light_white()       "\x1B[47m"

typedef string_t ansi_color_t[sizeof(color_text_magenta())];

#ifdef __cplusplus
}
#endif

#endif
