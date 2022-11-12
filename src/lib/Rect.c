#include <Rect.h>

Rect new_rect(void) {
	Rect rect;
	rect.init = &init_rect2;
	rect.update = &update_rect;
	rect.cleanup = &cleanup_rect;
	return rect;
}

void init_rect2(Rect* rect, Vector2D position, int width, int height, RGBColor color) {
	POLY_F4 poly;
	Vector2D direction;
	Vector2D velocity;
	
	SetPolyF4(&poly);
	setRGB0(&poly, color.red, color.green, color.blue);
	
	setXY4(
		&poly, position.x, position.y,			// top_left.x,    top_left.y,
		position.x, position.y + height,		// bottom_left.x, bottom_left.y
		position.x + width, position.y,			// top_right.x,   top_right.y,
		position.x + width, position.y + height	// bottom_left.x, bottom_left.y
	);

	rect->prim_rect = poly;
	rect->width = width;
	rect->height = height;
	rect->direction = direction;
	rect->velocity = velocity;
}

void update_rect(Rect* rect, Vector2D position) {
	move_to_pos(rect, position);
}

void cleanup_rect(Rect* rect) {
	rect->init = NULL;
	rect->update = NULL;
	rect->cleanup = NULL;	
}

void move_to_pos(Rect* rect, Vector2D position) {
	rect->prim_rect.x0 = position.x;
	rect->prim_rect.y0 = position.y;
	
	rect->prim_rect.x1 = position.x;
	rect->prim_rect.y1 = position.y + rect->height;
	
	rect->prim_rect.x2 = position.x + rect->width;
	rect->prim_rect.y2 = position.y;
	
	rect->prim_rect.x3 = rect->prim_rect.x2;
	rect->prim_rect.y3 = rect->prim_rect.y1;
}
