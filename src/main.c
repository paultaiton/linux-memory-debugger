#include <curses.h>
#include <menu.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

const static char *pause_message = "Press F1 key to exit...";

const static char *main_menu_choices[] = {
                        "Choice 1",
                        "Choice 2",
                        "Choice 3",
                        "Choice 4",
                        "Exit",
                        };

//ITEM *main_menu_items[ARRAY_SIZE(main_menu_choices) + 1]; //= (ITEM**)calloc(number_of_choices +1, sizeof(ITEM *));
//ITEM *main_menu_items[6]; //= (ITEM**)calloc(number_of_choices +1, sizeof(ITEM *));
// ITEM *main_menu_items[ARRAY_SIZE(main_menu_choices) + 1]; //= (ITEM**)calloc(number_of_choices +1, sizeof(ITEM *));

int main (int argc, const char *argv[]){
    static ITEM *main_menu_items[ARRAY_SIZE(main_menu_choices) + 1];
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    // nodelay(stdscr, TRUE); // getch does not block, and will return ERR if no input is ready.

    mvprintw(20, 0, pause_message);
    mvprintw(21, 0, "PID: %u", getpid());
    mvprintw(22, 0, "Columns: %u", COLS );
    mvprintw(23, 0, "Lines: %u", LINES);

    int number_of_choices = ARRAY_SIZE(main_menu_choices);
    // ITEM **main_menu_items = (ITEM**)calloc(number_of_choices +1, sizeof(ITEM *));
    for(int i=0; i < number_of_choices; i++) {
        main_menu_items[i] = new_item(main_menu_choices[i], main_menu_choices[i]);
        if (main_menu_items[i]== NULL) {
            perror("ERROR E001: failure while instantiating menu_items.\n");
            endwin();
            exit(1);
        }
    }
    main_menu_items[number_of_choices] = (ITEM *)NULL;

    MENU *main_menu = new_menu(main_menu_items);
    post_menu(main_menu);

    refresh();

    int key;
    while((key = getch()) != KEY_F(1)) {
        switch(key) {
            case KEY_DOWN:
                menu_driver(main_menu, REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                menu_driver(main_menu, REQ_UP_ITEM);
                break;
        }
    }

    unpost_menu(main_menu);
    // refresh();

    getch();


    free_menu(main_menu);
    for(int i=0; i < number_of_choices; i++) {
        free_item(main_menu_items[i]);
    }
    endwin();
}
