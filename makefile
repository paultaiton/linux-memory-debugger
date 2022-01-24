CC=gcc
CFLAGS=-O3 -Wall -march=native -pipe
FORMAT=elf64

all: bin/linux-memory-debugger

bin:
	mkdir bin

lib:
	mkdir lib

####################################################

bin/linux-memory-debugger: src/main.c bin
	gcc ${CFLAGS} -o bin/linux-memory-debugger src/main.c
	strip bin/linux-memory-debugger

####################################################

clean:
	rm -f lib/* bin/* 
