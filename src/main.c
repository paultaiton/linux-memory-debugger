#include <curses.h>
#include <menu.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "menu_defs.c"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

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

	mvprintw(20, 0, "%s", pause_message);
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

	static int key;
	static int quit = 0;
	ITEM *selected_item = current_item(main_menu);
	while(quit == 0){
		selected_item = current_item(main_menu);
		mvprintw(8, 0, "Selected item is %p", selected_item);
		mvprintw(9, 0, "Exit item is %p", main_menu_items[4]);
		key = getch();
		move(10, 0);
		clrtoeol();
		printw("Input was %u, %s", key, keyname(key));
		mvprintw(11, 0, "Enter is %u, %x", KEY_ENTER, KEY_ENTER );
		switch(key) {
			case KEY_DOWN:
				menu_driver(main_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(main_menu, REQ_UP_ITEM);
				break;
			//case KEY_RIGHT:
			case KEY_ENTER:
				//if (selected_item == (ITEM*)main_menu_choices[4]) {
				if (selected_item == main_menu_items[4]) {
					quit = 1;
				}
				break;
		}
	}

	unpost_menu(main_menu);

	free_menu(main_menu);
	for(int i=0; i < number_of_choices; i++) {
		free_item(main_menu_items[i]);
	}
	endwin();
}

