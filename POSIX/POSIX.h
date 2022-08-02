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

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include "Ansi_Sequences.h"
#include "../compiler.port/Data_Types.h"

#define terminal_flush()            fflush(stdout)

extern string_t Terminal_Name[];

void ecio_print_confined_text(const string_t *text, int offset, int maxLen);

void ecpopen(string_t *command, string_t *respond, size_t respond_size);
BOOL ecio_terminal_supports_utf();
void ecio_load_tty_name();
int  ecio_terminal_rows();
int  ecio_terminal_columns();
int  ecio_terminal_process_ID();

#ifdef __cplusplus
}
#endif
