#ifndef HANDLECONSOLE_H
#define HANDLECONSOLE_H

#include <stdbool.h>

#include "./KeyEvents.h"
#include "./StringTypes.h"

//Set macros for Console creation
#define CS_MENU "CS_MENU"
#define CS_YN "CS_YN"

//Set macros to define the expected number of elements in Console
#define MENU_ITEMS 6
#define YN_ITEMS 2

//Handle the elements of Menu Screen on Console
StdOutput* HandleConsoleElements(const char*);
//Console Screen
bool Console(const char*, int);
//Console Screen for bool operations
//Run the Menu loop and the Console in general terms
bool RunConsole(StdOutput*, const char*, int);
//Handle Console events
ConsoleEvent HandleEvents(StdOutput*, int);
//Refresh the Console Elements;
void RefreshConsole(StdOutput*, int, int);
//Clear Console without blink
void ClearConsole(void);
//Make Console return to default settings
void StandardConsole(void);

#endif