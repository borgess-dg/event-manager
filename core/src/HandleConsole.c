#include "../include/HandleConsole.h"

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>

#include "../include/KeyEvents.h"
#include "../include/StringTypes.h"
#include "../include/Register.h"

//Handle the elements that will be used in Console Menu
StdOutput* HandleConsoleElements(const char* SIGNAL){
    static StdOutput menuOptions[6];
    //Fill the menu options array
    if(!strcmp(SIGNAL, CS_MENU)){
        strcpy(menuOptions[0].output, "Cadastrar evento.\n");
        strcpy(menuOptions[1].output, "Pesquisar Evento.\n");
        strcpy(menuOptions[2].output, "Ingressos Vendidos.\n");
        strcpy(menuOptions[3].output, "Exibir resultado por evento.\n");
        strcpy(menuOptions[4].output, "Exibir resultado geral.\n");
        strcpy(menuOptions[5].output, "Sair.");
    }
    if(!strcmp(SIGNAL, CS_YN)){
        strcpy(menuOptions[0].output, "> SIM.");
        strcpy(menuOptions[1].output, "\t> NÃO.\n");
    }

    return menuOptions;
}

//Get Console elements and call Menu
bool Console(const char* SIGNAL, int ITEMS){
    StdOutput* consoleElements = HandleConsoleElements(SIGNAL);
    system("cls");
    printf("\e[?25l");
    return RunConsole(consoleElements, SIGNAL, ITEMS);
}

//Run the Menu in Console
bool RunConsole(StdOutput* consoleElements, const char* SIGNAL, int ITEMS){
    ConsoleEvent getEvent;
    while(true){
        getEvent = HandleEvents(consoleElements, ITEMS);
        //Determine the action after menu choices
        if(getEvent.keyPressed == KEY_ENTER){
            if(!strcmp(SIGNAL, CS_MENU))
                switch(getEvent.cursor){
                    //Call the function to Register Events
                    case 0:
                        EventRegister();
                        break;
                    //This case makes the exit function
                    case 5:
                        StandardConsole();
                        break;
                    default:
                        EventRegister();
                        break;
                }
            else if(!strcmp(SIGNAL, CS_YN)){
                switch(getEvent.cursor){
                    case 0:
                        getEvent.yesOrNot = true;
                        break;
                    case 1:
                        getEvent.yesOrNot = false;
                        break;
                    default:
                        getEvent.yesOrNot = true;
                        break;
                }
            }
            break;
        }
        ClearConsole();
    }
    return getEvent.yesOrNot;
}

//Refresh the Console Menu based on the position of cursor
void RefreshConsole(StdOutput* menuOptions, int cursorPosition, int ITEMS){

    for(int i = 0; i < ITEMS; i++)
            if(i == cursorPosition){
                printf("\033[0;31m");
                printf("%s", menuOptions[i].output);
            }
            else{
                printf("\033[0m");
                printf("%s", menuOptions[i].output);
            }
}

//Handle the keyboard events and returns the Event to RunConsole() loop's
ConsoleEvent HandleEvents(StdOutput* menuOptions, int ITEMS){
    static int cursorPosition = 0;
    ConsoleEvent e;
    RefreshConsole(menuOptions, cursorPosition, ITEMS);
    e.keyPressed = getch();
    if(e.keyPressed == KEY_DOWN){
        if(cursorPosition == ITEMS-1)
            cursorPosition = -1;
        cursorPosition++;
    }
    else if(e.keyPressed == KEY_UP){
        if(cursorPosition == ITEMS-ITEMS)
            cursorPosition = ITEMS;
        cursorPosition--;
    }
    e.cursor = cursorPosition;
    return e;
}

//Clear the Console
void ClearConsole(void)
{	
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

//Make Console return to default settings
void StandardConsole(void){
    system("cls");
    printf("\e[?25h");
    printf("\033[0m");
}