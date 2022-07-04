#include "../include/Register.h"

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/HandleConsole.h"

void EventRegister(void){
    StandardConsole();
    bool test = Console(CS_YN, YN_ITEMS);
    printf("%i", test);
}