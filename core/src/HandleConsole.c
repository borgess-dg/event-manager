#include "../include/HandleConsole.h"

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

#include "../include/KeyEvents.h"
#include "../include/StringTypes.h"

//Handle the elements that will be used in Console Menu
StdOutput* HandleConsoleElements(void){
    static StdOutput menuOptions[6];
    //Fill the menu options array
    strcpy(menuOptions[0].output, "Cadastrar evento.\n");
    strcpy(menuOptions[1].output, "Pesquisar Evento.\n");
    strcpy(menuOptions[2].output, "Ingressos Vendidos.\n");
    strcpy(menuOptions[3].output, "Exibir resultado por evento.\n");
    strcpy(menuOptions[4].output, "Exibir resultado geral.\n");
    strcpy(menuOptions[5].output, "Sair.");

    return menuOptions;
}

//Get Console elements and call Menu
void Console(){
    StdOutput* consoleElements = HandleConsoleElements();
    RunConsole(consoleElements);
}

//Run the Menu in Console
void RunConsole(StdOutput* consoleElements){
    Event getEvent;
    while(true){
        getEvent = HandleEvents(consoleElements);
        if(getEvent.keyPressed == KEY_ENTER)
            break;
        ClearConsole();
    }
}

//Refresh the Console Menu based on the position of cursor
void RefreshConsole(StdOutput* menuOptions, int cursorPosition){

    system("cls");
    printf("\e[?25l");
    for(int i = 0; i < 6; i++)
            if(i == cursorPosition){
                printf("\033[0;31m");
                printf("%s%s", "-> ", menuOptions[i].output);
            }
            else{
                printf("\033[0m");
                printf("%s", menuOptions[i].output);
            }
}

//Handle the keyboard events and returns the Event to RunConsole() loop's
Event HandleEvents(StdOutput* menuOptions){
    static int cursorPosition = 0;
    Event e;
    RefreshConsole(menuOptions, cursorPosition);
    e.keyPressed = getch();
    if(e.keyPressed == KEY_DOWN){
        if(cursorPosition == 5)
            cursorPosition = -1;
        cursorPosition++;
    }
    else if(e.keyPressed == KEY_UP){
        if(cursorPosition == 0)
            cursorPosition = 6;
        cursorPosition--;
    }
    else if(e.keyPressed == KEY_ENTER){
            //Call a X function
    }
    return e;
}

//Clear the Console
void ClearConsole(void)
{	
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
    printf("\e[2J\e[2H");
}