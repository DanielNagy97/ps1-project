#ifndef ENGINE_H
#define ENGINE_H

#include <display.h>
#include <libetc.h>
#include <controller.h>

typedef struct {
	POLY_F4 rect;
	int width;
	int height;
	int dir_x;
	int dir_y;
	int velocity_x;
	int velocity_y;
} Element;

void update_element_position(Element* element, float damping);
void update_element_directions_with_pad(Element* element, int speed);

#endif