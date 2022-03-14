#ifndef _DHANDA_UTIL_H_
#define _DHANDA_UTIL_H_

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_WHITE    "\x1b[37m"
#define ANSI_RESET          "\x1b[0m"

#define ANSI_BG_RED         "\x1b[41m"
#define ANSI_BG_GREEN       "\x1b[42m"
#define ANSI_BG_YELLOW      "\x1b[43m"

#define ANSI_BLINK          "\x1b[5m"
#define ANSI_BOLD           "\x1b[1m"

#define start_cmdline_color() printf(ANSI_BOLD ANSI_COLOR_CYAN);
#define end_cmdline_color()   printf(ANSI_RESET); fflush(stdout);

#if defined(DEBUG)
#define debug_print(fmt) fprintf(stderr, "%s:%s:%d: %s\n", __FILE__, __func__, __LINE__, fmt);
#else
#define debug_print(fmt)
#endif

int get_line(char line[], int size);
int get_string(char line[], int size);

#endif
