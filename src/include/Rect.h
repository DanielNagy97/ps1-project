#ifndef RECT_H
#define RECT_H

#include <display.h>
#include <Vector2D.h>
#include <RGBColor.h>
#include <Dimensions2D.h>
#include <BoundingBox2D.h>

typedef struct Rect Rect;

struct Rect
{
	POLY_F4 prim_rect;
	Vector2D position;
	Dimensions2D dimensions;
	BoundingBox2D bounding_box;
	void (*init)(Rect *, Vector2D, Dimensions2D, RGBColor);
	void (*update)(Rect *);
	void (*cleanup)(Rect *);
};

Rect new_rect(void);
void init_rect2(Rect *, Vector2D, Dimensions2D, RGBColor);
void update_rect(Rect *);
void cleanup_rect(Rect *);
void move_to_pos(Rect *, Vector2D);

#endif
