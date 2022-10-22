# ----------------------------
# PlayStation 1 Psy-Q MAKEFILE
# ----------------------------

CC = ccpsx
CFLAGS = -O3 -Xo$80010000
INCLUDE = -Isrc/include
SOURCE = src/main.c src/lib/display.c
OUTPUT = bin/main.cpe,bin/main.sym,bin/mem.map

all:
	$(CC)$(CFLAGS)$(SOURCE) -o$(OUTPUT)$(INCLUDE)
	cpe2x /ce bin/main.cpe
