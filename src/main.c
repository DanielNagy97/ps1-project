#include <main.h>

void initialize();
void update(Element* element, int speed, float damping);

int main() {
	Element element;
	char text[100];

	initialize();

	element.rect = init_rect(10, 10, 10, 50, 50, 10, 50, 50); //top_left, bottom_left, top_right, bottom_right
	element.width = element.rect.x2 - element.rect.x0;
	element.height = element.rect.y1 - element.rect.y0;
	
	while (1) {
		update(&element, 40, 0.95);

		sprintf(text, "Hello world!\n\ndir_x: %d(%d)\n\ndir_y: %d(%d)\n\nNellyke 2022", element.dir_x, element.velocity_x, element.dir_y, element.velocity_y);
		FntPrint(text);

		DrawPrim(&element.rect);

		display();
	}

	return 0;
}

void initialize() {
	init_graphics();
	init_pad();
	init_debugfont();
}

void update(Element* element, int speed, float damping) {
	update_element_directions_with_pad(element, speed);
	update_element_position(element, damping);
}