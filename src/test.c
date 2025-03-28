// Compile with /std:c11

#include <stdio.h>
#include <stdalign.h>
#include <stdlib.h>

typedef struct 
{
	int value; // aligns on a 4-byte boundary. There will be 28 bytes of padding between value and alignas
	alignas(32) char alignedMemory[32]; // assuming a 32 byte friendly cache alignment
} cacheFriendly; // this struct will be 32-byte aligned because alignedMemory is 32-byte aligned and is the largest alignment specified in the struct

int main (int argc, const char *argv[]){
	printf("sizeof(cacheFriendly): %lu\n", sizeof(cacheFriendly)); // 4 bytes for int value + 32 bytes for alignedMemory[] + padding to ensure  alignment
	printf("alignof(cacheFriendly): %lu\n", alignof(cacheFriendly)); // 32 because alignedMemory[] is aligned on a 32-byte boundary

	/* output
		sizeof(cacheFriendly): 64
		alignof(cacheFriendly): 32
	*/
	exit(0);
}
