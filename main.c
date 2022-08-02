
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

#include <time.h>
#ifndef __linux__
#error "This project is targeted to be run ONLY on GNU Linux based operating systems."
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdlib.h>
#include "compiler.port/Attributes.h"
#include "compiler.port/Data_Types.h"
#include "POSIX/Ansi_Sequences.h"
#include "POSIX/POSIX.h"
#include "Parse/Argv.h"
#include "database/database.h"
#include "database/emoji.h"


constructor void before_main(void)
{
    printf("size = %d\r\n", (int)sizeof(ec_elp_profiles));
    printf ("\r\nBefore main()\r\n");
}

destructor void after_main(void)
{
    free(ec_elp_profiles);
    printf ("\r\nAfter main()\r\n");
}

int project_main(int argc, string_t *argv[])
{
    emoji_t candy;
    emoji_t emoji;
    ecapi_parse_argv(argc, argv);
    ecio_load_tty_name();
    ec_elp_profiles = (ec_elp_profile *)malloc(sizeof(ec_elp_profiles) * 5);

    emojicpy(candy, emoji_candy2);
    ec_elp_analogue_clock_now(emoji);

    printf("Time  = " printf_emoji() end_line(), emoji);
    printf("Candy = " printf_emoji() end_line(), candy);
    printf("Size of color code = %d\r\n", (int)sizeof(color_text_magenta()));
    printf("Size of emoji      = %d\r\n", (int)sizeof(candy));

    printf("Some random text " printf_int(1,1) " " printf_int(1,1) " " printf_int(1,1) end_line(), 1, 2, 3);

    printf("%s\r\n", Terminal_Name);
    if(ecio_terminal_supports_utf())
        printf("utf\r\n");
    else
        printf("ascii\r\n");

    /*printf("Terminal name: " printf_string() end_line(), Terminal_Name);*/
    return EXIT_SUCCESS;
}

#ifndef EXOTIC_CANDY_PRIVATE_API
int main(int argc, string_t *argv[])
{
    return project_main(argc, argv);
}
#endif

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus

#include <iterator>
#include <ostream>
#include <string>
#include <vector>
#define LOG_PROJECT_NAME    DISABLED
#define LOG_STATE           DISABLED
#define LOG_LINE_NUMBER     DISABLED
#define LOG_FILE_NAME       DISABLED
#define LOG_LEVEL_INTERNAL  log_all
#define LOG_HEADER_NAME     "linux.prompt"
#include <ec/log.h>

#ifdef __cplusplus

bool isEmojiAllowed = false;
std::string ttyName = "";
int columnsCount;

std::string getTTY_Name()
{
    return cxxstrjoin(cxxpopen("echo $TERM"));
}

void loadTTYinfo()
{
    columnsCount = ecio_terminal_columns();
    ttyName = getTTY_Name();
    if (ttyName != "linux")
        isEmojiAllowed = true;
}

std::string getCurrentClockEmoji()
{
    std::vector<std::string> clocks = {emoji_clocks};
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    int hour = now->tm_hour * 2;

    if(now->tm_min <= 15)
        hour += 0;
    else if(now->tm_min <= 45)
        hour += 1;
    else
        hour += 2;

    hour = hour % static_cast<int>(clocks.size());

    return clocks[hour];
}

std::string getUserName()
{
    std::string userName = cxxstrjoin(cxxpopen("whoami"));
    if(userName == "root")
        userName = std::string(color_text_light_red()) + std::string(" ") + userName + std::string(" ") + std::string(color_reset());
    else if(userName == "exoticcandy")
        userName = std::string(color_text_magenta()) + std::string(" ") + emoji_candy2 + std::string(" Exotic Candy ") + emoji_candy2 + std::string(" ") + std::string(color_reset());
    else
        userName = std::string(color_reset()) + std::string(" ") + userName + std::string(" ") + std::string(color_reset());
    return userName;
}

std::string getPath()
{
    bool insideHome       = false;
    std::string path      = cxxstrjoin(cxxpopen("pwd"));
    std::string userName  = cxxstrjoin(cxxpopen("whoami"));
    std::string userHome  = cxxstrjoin(cxxpopen(std::string("echo ~") + userName)) + "/";
    std::string userColor = std::string(color_text_light_cyan());

    std::string printPath;

    std::vector<std::string> chunkedPath = cxxsplitpath(path);
    std::vector<std::string> chunkedHome = cxxsplitpath(userHome);

    if(userName == "root")
        userColor = std::string(color_text_red());
    if(path.starts_with(userHome))
    {
        path.erase(0, userHome.length());
        insideHome = true;
    }

    if(insideHome == true)
        chunkedPath.erase(chunkedPath.begin(), chunkedPath.begin() + chunkedHome.size());
    else
        chunkedPath.erase(chunkedPath.begin(), chunkedPath.begin() + 1);

    if((*(chunkedPath.end() - 1)).length() > 15)
        *(chunkedPath.end() - 1) = std::string(color_text_blue()) + (chunkedPath.end() - 1)->substr(0, 7) + std::string(utf_three_dots) + (chunkedPath.end() - 1)->substr((chunkedPath.end() - 1)->length() - 7) + std::string(color_reset());

    if(chunkedPath.size() == 1)
        printPath = chunkedPath[0];
    else
        printPath = std::string(color_text_yellow()) + std::string(utf_three_dots) + std::string("/") + std::string(color_reset()) + *(chunkedPath.end() - 1);

    if(insideHome)
        path = userColor + std::string("~/") + std::string(color_reset()) + printPath;
    else
        path = userColor + std::string("/") + std::string(color_reset()) + printPath;
    return path;
}

#endif

#ifdef __cplusplus
extern "C"
{
#endif



int project_main()
{
    loadTTYinfo();

    std::vector2d<std::string> test = cxx2dstrmatrix(std::string(emoji_head_explode), columnsCount, 3);
    //std::cout<<cxxstrjoin2d(test)<<std::endl<<"end 1"<<std::endl;
    std::cout<<std::endl;

    std::vector2d<std::string> test2 = cxx2dstrmatrix(std::string("."), columnsCount, 3);
    std::cout<<cxxstrjoin2d(test2)<<std::endl<<"end 2"<<std::endl;

    for(size_t i = 0; i < test2.size(); i++)
    {
        for(size_t j = 0; j < test2[0].size() / 2; j++)
        {
            std::cout<<emoji_head_explode;//test[i][j];
        }
    }
    std::cout<<test[0][0]<<std::endl;
    std::cout<<test.size()<<"\t"<<test2.size()<<std::endl;
    std::cout<<test[0].size()<<"\t"<<test2[0].size()<<std::endl;

/*
    std::cout<<std::endl<<std::endl<<
               "╭─┤"<<getCurrentClockEmoji()<<"├─╢"<<getUserName()<<":~/src╟─┤(✿◠‿◠)├─┄┄┈"<<std::endl<<
               "╰>"<<std::endl;

    std::cout<<std::endl<<std::endl<<
               "╭─┤"<<getCurrentClockEmoji()<<"├─╢mark@bender:~/src╟─┤(✿◠‿◠)├─┄┄┈"<<std::endl<<
               "╰>"<<std::endl;

    std::cout<<std::endl<<std::endl<<
               "╭─┤"<<getCurrentClockEmoji()<<"├─╢mark@bender:~/src╟─┤(✿◠‿◠)├─╮"<<std::endl<<
               "╰>"<<std::endl;
*/



    std::cout<<std::endl<<std::endl<<
               "╭─┤"<<getCurrentClockEmoji()<<"├─╢"<<getUserName()<<"╟─┐ "<<getPath()<<" ┌─┤(✿◠‿◠)├─┄┄┈"<<std::endl<<
               "╰─>"<<std::endl;

    std::cout<<std::endl<<std::endl<<
               "╭─┤"<<getCurrentClockEmoji()<<"├─╢"<<getUserName()<<"╟─╮ "<<getPath()<<" ╭─┤(✿◠‿◠)├───╮"<<std::endl<<
               "│                                                             ───╯"<<std::endl<<
               "╰─>"<<std::endl;

    std::cout<<std::endl<<std::endl<<
               "╭─┤"<<getCurrentClockEmoji()<<"├─╢"<<getUserName()<<"╟─┐ "<<getPath()<<" ┌─┤(✿◠‿◠)├───╮"<<std::endl<<
               "│                                                            ┈┄┄─╯"<<std::endl<<
               "╰─>"<<std::endl;

    int mustHaveSize = 56;

    std::string quote = "happy is the one who is something " + std::string(emoji_sparkling_heart) + std::string(emoji_sparkling_heart) + emoji_hand_over_mouth;
    /* in case of an emoji usage: */
    mustHaveSize += 5;
    /* in case of an emoji usage: */
    mustHaveSize += 5;
    /* in case of an emoji usage: */
    mustHaveSize += 5;
    quote.substr(0, mustHaveSize);
    //quote.append(mustHaveSize - quote.length(), ' '); //at the end
    quote.insert(quote.begin(), mustHaveSize - quote.length(), ' '); //begining
    quote += " ";

    std::cout<<std::endl<<std::endl<<
               "╭─┤"<<getCurrentClockEmoji()<<"├─╢"<<getUserName()<<"╟─┐ "<<getPath()<<" ┌─┤(✿◠‿◠)├───╮"<<std::endl<<
               "│   "<<quote<<"┈┄┄─╯"<<std::endl<<
               "╰─>"<<std::endl;

    std::cout<<std::endl<<std::endl<<
               "╭─┤"<<getCurrentClockEmoji()<<"├─╢"<<getUserName()<<"╟─> "<<getPath()<<" <─┤(✿◠‿◠)├─┄┄┈"<<std::endl<<
               "╰─>"<<std::endl;

    if(isEmojiAllowed == false)
    {
        std::cout<<std::endl<<std::endl<<
                   "┌─┤"<<getCurrentClockEmoji()<<"├─╢"<<getUserName()<<"╟─┐ "<<"~/***/testing "<<color_text_yellow()<<"***"<<color_reset()<<" ss kjfdk"<<" ┌─┤(✿◠‿◠)├───┐"<<std::endl<<
                   "│   "<<quote<<"    │"<<std::endl<<
                   "│   "<<quote<<"┈┄┄─┘"<<std::endl<<
                   "│   "<<std::endl<<
                   "└─>"<<std::endl;
    }

    std::cout<<"TERM: "<<ttyName<<"\t"<<"Emoji: "<<isEmojiAllowed<<"\tcolumns: "<<columnsCount<<"\r\n";

    return 0;
}

#ifdef __cplusplus
}
#endif







#endif












