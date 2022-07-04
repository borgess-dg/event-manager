#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "../include/HandleConsole.h"

//Detect OS, if is running in Windows OS executes the main function;
#ifdef _WIN32
    int main(void){

        setlocale(LC_ALL, "portuguese");
        Console(CS_MENU, MENU_ITEMS);
            
        return 0;
    }
#else
    printf("NO COMPATIBILITY FOR LINUX OR MAC!");
#endif