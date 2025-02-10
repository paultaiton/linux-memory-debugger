#include <curses.h>
#include <menu.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

//const char * hello_string = "Hello World!";
//char * hello_string = "Hello World!"; // immutable string
char hello_string[] = "Hello World!"; // mutable string
char pause_message[] = "Press F1 key to exit...";
char stuff[4096]; // just for testing

char *main_menu_choices[] = {
                        "Choice 1",
                        "Choice 2",
                        "Choice 3",
                        "Choice 4",
                        "Exit",
                  };

int main (int argc, const char *argv[]){
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // move(0, 0);
    // for (int i=0; i < strlen(hello_string); i++) {
    //     addch(hello_string[i]);
    // }

    // mvaddstr(0, 0, hello_string);
    // hello_string[4] = 'X';
    // mvaddstr(2, 0, hello_string);

    // mvprintw(14, 0, "PID: %u", getpid());
    // mvprintw(15, 0, "Columns: %u", COLS );
    // mvprintw(16, 0, "Lines: %u", LINES);

    int number_of_choices = ARRAY_SIZE(main_menu_choices);
    ITEM **main_menu_items = (ITEM**)calloc(number_of_choices +1, sizeof(ITEM *));
    for(int i=0; i < number_of_choices; i++) {
        main_menu_items[i] = new_item(main_menu_choices[i], main_menu_choices[i]);
    }
    main_menu_items[number_of_choices] = (ITEM *)NULL;

    MENU *main_menu = new_menu(main_menu_items);
    post_menu(main_menu);

    // mvaddstr(17, 0, pause_message);
    refresh();

    int key;
    while(key = getch() != KEY_F(1)) {
        switch(key) {
            case KEY_DOWN:
                menu_driver(main_menu, REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                menu_driver(main_menu, REQ_UP_ITEM);
                break;
        }
    }

    free_menu(main_menu);
    for(int i=0; i < number_of_choices; i++) {
        free_item(main_menu_items[i]);
    }
    endwin();
}
