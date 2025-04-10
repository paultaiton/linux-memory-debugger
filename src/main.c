#include <curses.h>
#include <menu.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "menu_defs.c"

int main (int argc, const char *argv[]){
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	// nodelay(stdscr, TRUE); // getch does not block, and will return ERR if no input is ready.

	mvprintw(20, 0, "%s", pause_message);
	mvprintw(21, 0, "PID: %u", getpid());
	mvprintw(22, 0, "Columns: %u", COLS );
	mvprintw(23, 0, "Lines: %u", LINES);


	refresh();

	call_main_menu();

	// free_menu(main_menu);
	// for(int i=0; i < number_of_choices; i++) {
	// 	free_item(main_menu_items[i]);
	// }
	endwin();
}
