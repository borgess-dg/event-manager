#ifndef KEY_EVENTS_H
#define KEY_EVENTS_H

//Set macros to Keyboard codes.
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_ENTER 13

//This struct makes the handling of Console Events more intuitive.
typedef struct{
    int keyPressed;
    int cursor;
    int yesOrNot;
}ConsoleEvent;

#endif