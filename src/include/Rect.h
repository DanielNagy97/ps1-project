#ifndef RECT_H
#define RECT_H

#include <display.h>
#include <Vector2D.h>
#include <RGBColor.h>


typedef struct Rect Rect;

struct Rect {
	POLY_F4 prim_rect;
	int width;
	int height;
	Vector2D direction;
	Vector2D velocity;
	void (* init)(Rect*, Vector2D, int, int, RGBColor);
	void (* update)(Rect*, Vector2D);
	void (* cleanup)(Rect*);
};

Rect new_rect(void);
void init_rect2(Rect*, Vector2D, int, int, RGBColor);
void update_rect(Rect*, Vector2D);
void cleanup_rect(Rect*);

void move_to_pos(Rect*, Vector2D);

#endif