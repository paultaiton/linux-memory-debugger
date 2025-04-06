#include <curses.h>

int failure() {
	return FALSE;
}

int success() {
	return TRUE;
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

//const static char *pause_message = "Press F1 key to exit...";
static char *pause_message = "Hello";

const static struct menu_item *main_menu_choices[] = {
	&choice1,
	NULL,
	NULL,
	NULL,
	};


// const static char *main_menu_choices[] = {
// 	"Choice 1",
// 	"Choice 2",
// 	"Choice 3",
// 	"Choice 4",
// 	"Exit",
// 	};
