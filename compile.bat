cls
ccpsx -O3 -Xo$80010000 src/main.c src/lib/display.c src/lib/engine.c -obin/main.cpe,bin/main.sym,bin/mem.map -Isrc/include
cpe2x /ce bin/main.cpe