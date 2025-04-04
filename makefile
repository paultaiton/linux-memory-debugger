CC=gcc

CFLAGS=-ggdb -O3 -Wall -march=native -pipe
FORMAT=elf64

all: bin lib bin/linux-memory-debugger bin/bss-user bin/test

bin:
	mkdir bin

lib:
	mkdir lib

####################################################

bin/linux-memory-debugger: src/main.c src/menu_defs.c
	gcc ${CFLAGS} -o bin/linux-memory-debugger src/main.c -lmenu -lncurses -ltinfo
	# strip bin/linux-memory-debugger

####################################################

bin/bss-user: src/bss_user.c
	gcc ${CFLAGS} -mcmodel=large -o bin/bss-user src/bss_user.c

####################################################

bin/test: src/test.c
	gcc ${CFLAGS} -o bin/test src/test.c

####################################################

clean:
	rm -f lib/* bin/* 
