CC=gcc
CFLAGS=-O3 -Wall -march=native -pipe
FORMAT=elf64

all: bin/linux-memory-debugger bin/bss-user bin/test

bin:
	mkdir bin

lib:
	mkdir lib

####################################################

bin/linux-memory-debugger: src/main.c bin
	gcc ${CFLAGS} -o bin/linux-memory-debugger src/main.c -lmenu -lncurses -ltinfo
	# strip bin/linux-memory-debugger

####################################################

bin/bss-user: src/bss_user.c bin
	gcc ${CFLAGS} -mcmodel=large -o bin/bss_user src/bss_user.c

####################################################

bin/test: src/test.c bin
	gcc ${CFLAGS} -o bin/test src/test.c

####################################################

clean:
	rm -f lib/* bin/* 
