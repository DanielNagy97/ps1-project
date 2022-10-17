# ----------------------------
# PlayStation 1 Psy-Q MAKEFILE
# ----------------------------

CC=wine ccpsx
CFLAGS=-Ilib -O3 -Xo$80010000

all:
	#del mem.map
	#del main.sym
	#del main.exe
	#del main.cpe
	#cls

	$(CC) main.c lib/display.c -o bin/main.cpe,bin/main.sym,bin/mem.map $(CFLAGS)
	#cpe2x /ce main.cpe
