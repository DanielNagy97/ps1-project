cls
ccpsx -O3 -Xo$80010000 src/main.c src/lib/display.c src/lib/controller.c src/lib/engine.c src/lib/Rect.c src/lib/GameObject.c src/lib/Layer.c src/lib/Scene.c src/lib/GameEngine.c -obin/main.cpe,bin/main.sym,bin/mem.map -Isrc/include
cpe2x /ce bin/main.cpe