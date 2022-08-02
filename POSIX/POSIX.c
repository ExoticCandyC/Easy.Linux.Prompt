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

#ifdef __cplusplus
extern "C"
{
#endif

#include "POSIX.h"

#ifdef EXOTIC_CANDY_PRIVATE_API
weak
#endif
void ecio_print_confined_text(const string_t *text, int offset, int maxLen)
{
    string_t formatStr[0xFF];
    iterator_t(const string_t) itr;
    iterator_t(const string_t) end;
    iterator_t(const string_t) seeker;
    itr = text;
    end = itr + strlen(itr);
    printf(cursor_home());
    while(itr < end)
    {
        if((int)strlen(itr) < maxLen)
            seeker = end;
        else
        {
            seeker = itr + maxLen;
            while(*(--seeker) != ' ' && seeker > itr);
        }
        sprintf(formatStr, cursor_move_right_variable() printf_percent() "."
                printf_int(1,1) "s" end_line(), offset, (int)(seeker - itr));
        printf(formatStr, itr);
        itr = seeker + 1;
    }
}

string_t Terminal_Name[0xFF];

extern int pclose (FILE *__stream);
extern FILE *popen (const char *__command, const char *__modes)
  __attribute_malloc__ __attr_dealloc (pclose, 1) __wur;

#ifdef EXOTIC_CANDY_PRIVATE_API
weak
#endif
void ecpopen(string_t *command, string_t *respond, size_t respond_size)
{
    FILE *fp;

    fp = popen(command, "r");

    if(fgets(respond, (int)respond_size, fp) == NULL)
        return;

    pclose(fp);
}

void ecio_load_tty_name()
{
    iterator_t(string_t) itr;
    ecpopen("echo $TERM", Terminal_Name, sizeof(Terminal_Name));
    itr = Terminal_Name + strlen(Terminal_Name) - 1;
    while(itr > Terminal_Name)
        if(*itr-- == '\n')
            *(itr + 1) = '\0';
}

BOOL ecio_terminal_supports_utf()
{
    if(strcmp(Terminal_Name, "linux") == 0)
        return FALSE;
    return TRUE;
}

#ifdef EXOTIC_CANDY_PRIVATE_API
weak
#endif
int ecio_terminal_rows()
{
    char respond[10];
    ecpopen("tput lines", respond, sizeof(respond));
    return atoi(respond);
}


#ifdef EXOTIC_CANDY_PRIVATE_API
weak
#endif
int ecio_terminal_columns()
{
    char respond[10];
    ecpopen("tput cols", respond, sizeof(respond));
    return atoi(respond);
}


#ifdef EXOTIC_CANDY_PRIVATE_API
weak
#endif
int ecio_terminal_process_ID()
{
    char respond[10];
    ecpopen("echo $$", respond, sizeof(respond));
    return atoi(respond);
}

#ifdef __cplusplus
}
#endif
