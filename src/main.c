#include <stdlib.h>
#include <display.h>
#include <controller.h>

typedef struct {
	POLY_F4 rect;
	int x;
	int y;
	int velocity_x;
	int velocity_y;
} Pad;

void initialize();
void update(Pad* pad);

int main() {
	LINE_F2 line;
	Pad pad;

	char text[100];

	initialize();

	line = init_line(64, 50, 150, 150);
	pad.rect = init_rect(10, 10, 10, 50, 50, 10, 50, 50);
	
	while (1) {
		update(&pad);
		sprintf(text, "Hello world!\n\nx: %d(%d)\n\ny: %d(%d)", pad.x, pad.velocity_x, pad.y, pad.velocity_y);
		FntPrint(text);
		DrawPrim(&line);
		DrawPrim(&pad.rect);
		display();
	}

	return 0;
}

void initialize() {
	init_graphics();
	initializePad();
	init_debugfont();
	
}

void update(Pad* pad) {
	int speed = 40;
	padUpdate();
	pad->velocity_x *= 0.95;
	pad->velocity_y *= 0.95;
	if(padCheck(Pad1Up)) {
		pad->y = -1;
		pad->velocity_y = speed;
	}
	if(padCheck(Pad1Down)) {
		pad->y = 1;
		pad->velocity_y = speed;
	}
	if(padCheck(Pad1Left)) {
		pad->x = -1;
		pad->velocity_x = speed;
	}
	if(padCheck(Pad1Right)) {
		pad->x = 1;
		pad->velocity_x = speed;
	}
	
	move_rect(&pad->rect, pad->x, pad->y, pad->velocity_x, pad->velocity_y);
}