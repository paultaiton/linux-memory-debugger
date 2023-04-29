#include <stdlib.h>
#include <stdio.h>

struct mmap_segment_details{
    void *start;
    void *end;
    char *name;
    short name_length;
    _Bool in_use;
};

void heap_menu(){
    printf("HEAP BREAK MENU\n");
    printf("#######################################");
    printf("\n\n");
    return;
}

void anon_mmap_menu(){
    printf("ANONYMOUS MMAP MENU\n");
    printf("#######################################");
    printf("\n\n");
    return;
}

void file_mmap_menu(){
    printf("FILE MMAP MENU\n");
    printf("#######################################");
    printf("\n\n");
    return;
}

short main_menu(){
    printf("MAIN MENU\n");
    printf("#######################################");
    printf("\n\n");
    printf(" 1  :  Heap Break \n");
    printf(" 2  :  Anonymous mmap \n");
    printf(" 3  :  File mmap \n");
    printf(" 0  :  Exit \n");
    printf("\nSelection : ");
    int selection = getchar();
    if (selection != '\n'){
        getchar();
    }
    printf("\n");
    return selection;
}

int main (int argc, const char *argv[]){
    short main_menu_selection = 0;
    while(1){
        main_menu_selection = main_menu();
        switch(main_menu_selection){
            case '0' :
                exit(0);
                break;
            case '1' :
                heap_menu();
                break;
            case '2' :
                anon_mmap_menu();
                break;
            case '3' :
                file_mmap_menu();
                break;
        }

    }
}

