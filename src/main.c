#include <curses.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc, const char *argv[]){
    initscr();
    cbreak();
    noecho();

    mvaddch(0, 0, 'H');
    addch('e');
    addch('l');
    addch('l');
    addch('o');
    addch(' ');
    addch('W');
    addch('o');
    addch('r');
    addch('l');
    addch('d');
    addch('!');
}

