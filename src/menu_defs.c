#include <curses.h>
#include <menu.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

static int quit_flag = 0;
int success() {
	return TRUE;
}
int failure() {
	return FALSE;
}
int quit() {
	quit_flag = 1;
	return 0;
}

struct menu_item {
	char *name;
	char *descritpion;
	int  (*invoker)();
	ITEM *curs_item;
} ;

struct menu_item choice1 = {
	.name = "Hello",
	.descritpion = "The Hello Task",
	.invoker = success,
	.curs_item = NULL
};

struct menu_item main_menu_quit = {
	.name = "EXIT",
	.descritpion = "quit the program",
	.invoker = quit,
	.curs_item = NULL
};

const static struct menu_item *main_menu_choices[] = {
	&choice1,
	&main_menu_quit,
	NULL,
	};

int call_main_menu() {
	static MENU* main_menu = NULL;
	static ITEM *main_menu_items[ARRAY_SIZE(main_menu_choices) + 1];
	if (main_menu == NULL) {
		for(int i=0; main_menu_choices[i] != NULL; i++) {
			main_menu_items[i] = new_item(main_menu_choices[i]->name, main_menu_choices[i]->descritpion);
			if (main_menu_items[i]== NULL) {
				perror("ERROR E001: failure while instantiating menu_items.\n");
				endwin();
				exit(1);
			}
		}
		main_menu = new_menu(main_menu_items);
	}
	post_menu(main_menu);

	int key;
	ITEM *selected_item;
	while(quit_flag == 0){
		selected_item = current_item(main_menu);
		mvprintw(8, 0, "Selected item is %p", selected_item);
		mvprintw(9, 0, "Exit item is %p", main_menu_items[1]); // TODO This is bad, don't use index.
		key = getch();
		move(10, 0);
		clrtoeol();
		printw("Input was %u, 0x%x, %s", key, key, keyname(key));
		mvprintw(11, 0, "Enter is %u, 0x%x", KEY_ENTER, KEY_ENTER );
		switch(key) {
			case KEY_DOWN:
				menu_driver(main_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(main_menu, REQ_UP_ITEM);
				break;
			case KEY_RIGHT:
				main_menu_choices[item_index(current_item(main_menu))]->invoker();
				break;
		}
	}
	unpost_menu(main_menu);
	return 0;
}

//const static char *pause_message = "Press F1 key to exit...";
static char *pause_message = "Hello";

