#ifndef BOUNDING_BOX_2D_H
#define BOUNDING_BOX_2D_H

#include <stdlib.h>
#include <Vector2D.h>


typedef struct BoundingBox2D BoundingBox2D;

struct BoundingBox2D {
	Vector2D min_point;
	Vector2D max_point;
	void (* init)(BoundingBox2D*, Vector2D, Vector2D);
	void (* update)(BoundingBox2D*, Vector2D, Vector2D);
	int (* check_overlapping)(BoundingBox2D*, BoundingBox2D*);
	void (* cleanup)(BoundingBox2D*);
};

BoundingBox2D new_bounding_box(void);
void init_bounding_box(BoundingBox2D*, Vector2D, Vector2D);
void update_bounding_box(BoundingBox2D*, Vector2D, Vector2D);
void cleanup_bounding_box(BoundingBox2D*);
int check_overlapping(BoundingBox2D*, BoundingBox2D*);

#endif