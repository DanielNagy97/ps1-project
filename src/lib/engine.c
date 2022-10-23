#include <engine.h>
#include <controller.h>

void update_element_directions_with_pad(Element* element, int speed) {
	padUpdate();

	if(padCheck(Pad1Up)) {
		element->dir_y = -1;
		element->velocity_y = speed;
	}
	if(padCheck(Pad1Down)) {
		element->dir_y = 1;
		element->velocity_y = speed;
	}
	if(padCheck(Pad1Left)) {
		element->dir_x = -1;
		element->velocity_x = speed;
	}
	if(padCheck(Pad1Right)) {
		element->dir_x = 1;
		element->velocity_x = speed;
	}
}

void update_element_position(Element* element, float damping) {
	int move_x;
	int move_y;
	int pos_x;
	int pos_y;
	
	move_x = (element->dir_x * (element->velocity_x * 0.1));
	move_y = (element->dir_y * (element->velocity_y * 0.1));
	
	pos_x = element->rect.x0 + move_x;
	pos_y = element->rect.y0 + move_y;
	
	if(pos_x <= 0) {
		pos_x = 0;
	}
	else if(pos_x + element->width >= SCREEN_WIDTH) {
		pos_x = SCREEN_WIDTH - element->width;
	}
	if(pos_y <= 0) {
		pos_y = 0;
	}
	else if(pos_y + element->height >= SCREEN_HEIGHT) {
		pos_y = SCREEN_HEIGHT - element->height;
	}
	
	move_rect_to_pos(&element->rect, pos_x, pos_y);
	element->velocity_x *= damping;
	element->velocity_y *= damping;
}
