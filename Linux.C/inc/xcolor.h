#ifndef _XCOLOR_
#define _XCOLOR_

    #ifdef _TEXT_COLOR_

        #define TEXT_BLACK      "\x1b[0;30m"
        #define TEXT_RED        "\x1b[0;31m"
        #define TEXT_GREEN      "\x1b[0;32m"
        #define TEXT_YELLOW     "\x1b[0;33m"
        #define TEXT_BLUE       "\x1b[0;34m"
        #define TEXT_PURPLE     "\x1b[0;35m"
        #define TEXT_INDIGO     "\x1b[0;36m"
        #define TEXT_WHITE      "\x1b[0;37m"

        #define TEXT_L_BLACK    "\x1b[1;30m"
        #define TEXT_L_RED      "\x1b[1;31m"
        #define TEXT_L_GREEN    "\x1b[1;32m"
        #define TEXT_L_YELLOW   "\x1b[1;33m"
        #define TEXT_L_BLUE     "\x1b[1;34m"
        #define TEXT_L_PURPLE   "\x1b[1;35m"
        #define TEXT_L_INDIGO   "\x1b[1;36m"
        #define TEXT_L_WHITE    "\x1b[1;37m"

        #define TEXT_NONE       "\x1b[0m"

    #else

        #define TEXT_BLACK
        #define TEXT_RED
        #define TEXT_GREEN
        #define TEXT_YELLOW
        #define TEXT_BLUE
        #define TEXT_PURPLE
        #define TEXT_INDIGO
        #define TEXT_WHITE

        #define TEXT_L_BLACK
        #define TEXT_L_RED
        #define TEXT_L_GREEN
        #define TEXT_L_YELLOW
        #define TEXT_L_BLUE
        #define TEXT_L_PURPLE
        #define TEXT_L_INDIGO
        #define TEXT_L_WHITE

        #define TEXT_NONE

    #endif // _TEXT_COLOR_

#endif // _XCOLOR_
