#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define PAGESIZE 4096


int main (int argc, const char *argv[]){
	static char bigarray1[0x500000000];
	static char bigarray2[0x500000000];
	static char bigarray3[0x5A0000000];

	printf("\n\nSize of bigarray1: 0x%lX", sizeof(bigarray1));
	printf("\nSize of bigarray1: %lu", sizeof(bigarray1));
	for(unsigned long i=0; bigarray1 + i < bigarray1 + sizeof(bigarray1); i += PAGESIZE) {
		bigarray1[i] = 'X';
	}
	printf("\n\nPress enter to continue...");
	getchar();

	printf("\n\nSize of bigarray2: 0x%lX", sizeof(bigarray2));
	printf("\nSize of bigarray2: %lu", sizeof(bigarray2));
	for(unsigned long i=0; bigarray2 + i < bigarray2 + sizeof(bigarray2); i += PAGESIZE) {
		bigarray2[i] = 'X';
	}
	printf("\n\nPress enter to continue...");
	getchar();

	printf("\n\nSize of bigarray3: 0x%lX", sizeof(bigarray3));
	printf("\nSize of bigarray3: %lu", sizeof(bigarray3));
	for(unsigned long i=0; bigarray3 + i < bigarray3 + sizeof(bigarray3); i += PAGESIZE) {
		bigarray3[i] = 'X';
	}
	printf("\n\nPress enter to exit...");
	getchar();

	exit(0);
}
