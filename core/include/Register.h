#ifndef REGISTER_H
#define REGISTER_H

typedef struct{
    int id;
    char name[255];
    char local[1024];
    char date[11];
    int tickets;
    double cousts;
}Event;

void EventRegister(void);

#endif