#include <Rect.h>


Rect new_rect(void) {
	Rect rect;
	Vector2D position;
	Dimensions2D dimensions;
	BoundingBox2D bounding_box = new_bounding_box();
	
	rect.position = position;
	rect.dimensions = dimensions;
	rect.bounding_box = bounding_box;
	rect.init = &init_rect2;
	rect.update = &update_rect;
	rect.cleanup = &cleanup_rect;
	return rect;
}

void init_rect2(Rect* rect, Vector2D position,
				Dimensions2D dimensions, RGBColor color) {
	POLY_F4 poly;
	Vector2D max_point = {
		position.x + dimensions.width,
		position.y + dimensions.height
	};
	
	SetPolyF4(&poly);
	setRGB0(&poly, color.red, color.green, color.blue);
	
	setXY4(
		&poly, position.x, position.y,				// topl.x, topl.y,
		position.x, position.y + dimensions.height,	// botl.x, botl.y
		position.x + dimensions.width, position.y,	// topr.x, topr.y,
		max_point.x, max_point.y					// botl.x, botl.y
	);

	rect->position = position;
	rect->prim_rect = poly;
	rect->dimensions = dimensions;
	
	rect->bounding_box.init(&rect->bounding_box, position, max_point);
}

void update_rect(Rect* rect) {
	Vector2D max_point = {
		rect->position.x + rect->dimensions.width,
		rect->position.y + rect->dimensions.height
	};
	move_to_pos(rect, rect->position);
	rect->bounding_box.update(&rect->bounding_box, rect->position, max_point);
	DrawPrim(&rect->prim_rect);
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
	rect->prim_rect.y1 = position.y + rect->dimensions.height;
	
	rect->prim_rect.x2 = position.x + rect->dimensions.width;
	rect->prim_rect.y2 = position.y;
	
	rect->prim_rect.x3 = rect->prim_rect.x2;
	rect->prim_rect.y3 = rect->prim_rect.y1;
}
