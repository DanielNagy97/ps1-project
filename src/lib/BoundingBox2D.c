#include <BoundingBox2D.h>

BoundingBox2D new_bounding_box(void)
{
	BoundingBox2D bounding_box;
	Vector2D min_point = {0, 0};
	Vector2D max_point = {0, 0};

	bounding_box.min_point = min_point;
	bounding_box.max_point = max_point;
	bounding_box.init = &init_bounding_box;
	bounding_box.update = &update_bounding_box;
	bounding_box.cleanup = &cleanup_bounding_box;
	bounding_box.check_overlapping = &check_overlapping;

	return bounding_box;
}

void init_bounding_box(BoundingBox2D *bounding_box,
					   Vector2D min_point, Vector2D max_point)
{
	bounding_box->min_point = min_point;
	bounding_box->max_point = max_point;
}

void update_bounding_box(BoundingBox2D *bounding_box,
						 Vector2D min_point, Vector2D max_point)
{
	bounding_box->min_point = min_point;
	bounding_box->max_point = max_point;
}

void cleanup_bounding_box(BoundingBox2D *bounding_box)
{
	bounding_box->init = NULL;
	bounding_box->update = NULL;
	bounding_box->cleanup = NULL;
	bounding_box->check_overlapping = NULL;
}

int check_overlapping(BoundingBox2D *self, BoundingBox2D *box)
{
	if (self->max_point.x < box->min_point.x || self->min_point.x > box->max_point.x)
	{
		return 0;
	}
	if (self->max_point.y < box->min_point.y || self->min_point.y > box->max_point.y)
	{
		return 0;
	}
	return 1;
}
