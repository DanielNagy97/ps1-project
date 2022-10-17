# ----------------------------
# PlayStation 1 Psy-Q MAKEFILE
# ----------------------------

CC=wine ccpsx
CFLAGS=-Isrc/include -O3 -Xo$80010000
SRCDIR=src
OUTDIR=bin
SOURCE=$(SRCDIR)/main.c $(SRCDIR)/lib/display.c
OUTPUT=$(OUTDIR)/main.cpe,$(OUTDIR)/main.sym,$(OUTDIR)/mem.map

$(info $(shell mkdir -p $(OUTDIR)))

all:
	$(CC) $(SOURCE) -o $(OUTPUT) $(CFLAGS)
