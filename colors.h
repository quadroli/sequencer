#ifndef COLORS
#define COLORS

#define RED       "\x1B[31m"
#define BLUE      "\x1B[34m"
#define GREEN     "\x1B[32m"
#define YELLOW    "\x1B[33m"
#define MAGENTA   "\x1B[35m"
#define DEFAULT   "\x1B[39m"

#ifdef __WIN32__
	#include <windows.h>
	#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
		#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
	#endif
	DWORD dwMode;
	DWORD 
	enableColorsOnWindows()
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hOut == INVALID_HANDLE_VALUE) return GetLastError();
		dwMode = 0;
		if (!GetConsoleMode(hOut, &dwMode))return GetLastError();
		dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		if (!SetConsoleMode(hOut, dwMode))return GetLastError();
		return 0;
	}
#endif /*end windows if*/
#endif /*end colors def*/
