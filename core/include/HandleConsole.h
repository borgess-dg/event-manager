#ifndef HANDLECONSOLE_H
#define HANDLECONSOLE_H

#include "./KeyEvents.h"
#include "./StringTypes.h"

//Handle the elements of Menu Screen on Console
StdOutput* HandleConsoleElements(void);
//Console Screen
void Console(void);
//Run the Menu loop and the Console in general terms
void RunConsole(StdOutput*);
//Handle Console events
Event HandleEvents(StdOutput*);
//Refresh the Console Elements;
void RefreshConsole(StdOutput*, int);
//Clear Console without blink
void ClearConsole(void);

#endif