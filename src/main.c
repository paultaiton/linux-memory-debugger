#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char * hello_string = "Hello World!";

int main (int argc, const char *argv[]){
    initscr();
    cbreak();
    noecho();

    move(0, 0);
    for (int i=0; i < strlen(hello_string); i++) {
        addch(hello_string[i]);
    }
    refresh();

    getchar();

    endwin();
}

