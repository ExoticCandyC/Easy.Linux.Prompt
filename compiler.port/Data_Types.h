
#pragma once

#include <math.h>
#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define ABS(value) \
    ((value < 0) ? (value * -1) : (value))

#if defined(__ARCH64__) || (defined(__CLANGD_SIMULATE__) && !defined(XC16))
#define printf_uint8(SPACE_PAD, ZERO_PAD)              "%" #SPACE_PAD "." #ZERO_PAD       "u"
#define printf_uint16(SPACE_PAD, ZERO_PAD)             "%" #SPACE_PAD "." #ZERO_PAD       "u"
#define printf_uint32(SPACE_PAD, ZERO_PAD)             "%" #SPACE_PAD "." #ZERO_PAD       "u"
#define printf_uint64(SPACE_PAD, ZERO_PAD)             "%" #SPACE_PAD "." #ZERO_PAD       "lu"
#define printf_int8(SPACE_PAD, ZERO_PAD)               "%" #SPACE_PAD "." #ZERO_PAD       "i"
#define printf_int16(SPACE_PAD, ZERO_PAD)              "%" #SPACE_PAD "." #ZERO_PAD       "i"
#define printf_int32(SPACE_PAD, ZERO_PAD)              "%" #SPACE_PAD "." #ZERO_PAD       "i"
#define printf_int64(SPACE_PAD, ZERO_PAD)              "%" #SPACE_PAD "." #ZERO_PAD       "li"
#define printf_int(SPACE_PAD, ZERO_PAD)                "%" #SPACE_PAD "." #ZERO_PAD       "d"
#define printf_double(SPACE_PAD, FLOATING_COUNT)       "%" #SPACE_PAD "." #FLOATING_COUNT "f"
#else
#define printf_uint8(SPACE_PAD, ZERO_PAD)              "%" #SPACE_PAD "." #ZERO_PAD "u"
#define printf_uint16(SPACE_PAD, ZERO_PAD)             "%" #SPACE_PAD "." #ZERO_PAD "u"
#define printf_uint32(SPACE_PAD, ZERO_PAD)             "%" #SPACE_PAD "." #ZERO_PAD "lu"
#define printf_uint64(SPACE_PAD, ZERO_PAD)             "%" #SPACE_PAD "." #ZERO_PAD "llu"
#define printf_int8(SPACE_PAD, ZERO_PAD)               "%" #SPACE_PAD "." #ZERO_PAD "i"
#define printf_int16(SPACE_PAD, ZERO_PAD)              "%" #SPACE_PAD "." #ZERO_PAD "i"
#define printf_int32(SPACE_PAD, ZERO_PAD)              "%" #SPACE_PAD "." #ZERO_PAD "li"
#define printf_int64(SPACE_PAD, ZERO_PAD)              "%" #SPACE_PAD "." #ZERO_PAD "lli"
#define printf_int(SPACE_PAD, ZERO_PAD)                "%" #SPACE_PAD "." #ZERO_PAD       "d"
#define printf_double(SPACE_PAD, FLOATING_COUNT)       "%" #SPACE_PAD "." #FLOATING_COUNT "f"
#endif

#define printf_percent()         "%%"
#define printf_string(LENGTH)    "%" #LENGTH "s"
#define printf_IP()              "%u.%u.%u.%u"
#define printf_MAC()             "%2.2X:%2.2X:%2.2X:%2.2X:%2.2X:%2.2X"
#define printf_hex8()            "%2.2X"
#define printf_hex16()           printf_hex8()  printf_hex8()
#define printf_hex24()           printf_hex16() printf_hex8()
#define printf_hex32()           printf_hex16() printf_hex16()
#define printf_hex64()           printf_hex32() printf_hex32()
#define printf_date()            printf_uint16(4,4) "/" printf_uint8(2,2) "/" printf_uint8(2,2)
#define printf_time()            printf_uint8(2,2)  ":" printf_uint8(2,2) ":" printf_uint8(2,2)
#define printf_timezone()        "%s" printf_uint8(2,2) ":" printf_uint8(2,2)
#define printf_phonenumber()     "+"  printf_uint64(12,12)
#define printf_emoji()           printf_string()

#define mask_number(value, mask) \
        (value & mask)

#define get_digit(value, index) \
        ((uint8_t)((index > 0) ? \
        ((uint64_t)(((uint64_t)ABS(value)) % ((uint64_t)(pow(10, index)))) /\
        ((uint64_t)(pow(10, (index - 1))))) : 0))

#define expand_phone_number(Value) \
        (((uint64_t)ABS(Value)) % 0xE8D4A51000)

#define expand_date(Year, Month, Day) \
        ((uint16_t)((Year < 100) ? (Year + 2000) : Year)), ((uint8_t)Month), ((uint8_t)Day)

#define expand_time(Hour, Minute, Second) \
        ((uint8_t)Hour), ((uint8_t)Minute), ((uint8_t)Second)

#define expand_timeZone(Hour, Minute) \
        (((int8_t)Hour < 0) ? "-" : "+"), (uint8_t)(ABS(Hour)), ((Minute == 0) ? 0 : 30)

typedef char string_t;

typedef struct tm stime_t;

typedef string_t * (*pointer_t)();

#define iterator_t(type) type*

#define iterator_move_forward(itr, size) itr += size;
#define iterator_move_back(itr, size)    itr -= size;
#define iterator_seek(itr, end, item)    \
    {                                    \
        while(*itr != item && itr < end) \
            itr++;                       \
    }

#define iterator_seek_next(itr, end, item)  \
    {                                       \
        itr++;                              \
        iterator_seek(itr, end, item);      \
    }

typedef enum
{
    Color_Name_None,
    Color_Name_Black,
    Color_Name_Red,
    Color_Name_Green,
    Color_Name_Yellow,
    Color_Name_Blue,
    Color_Name_Magenta,
    Color_Name_Cyan,
    Color_Name_White
} Color_Names;

#define EC_NULL ((void *)0)

#define Font_Weight_Normal 0
#define Font_Weight_Bold   1

#ifndef BOOL
#define BOOL    uint8_t
#endif

#ifndef TRUE
#define TRUE     1
#endif

#ifndef FALSE
#define FALSE    0
#endif

#ifdef __cplusplus
}
#endif

