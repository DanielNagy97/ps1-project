#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <Rect.h>

typedef struct GameObject GameObject;

struct GameObject
{
	Rect *rect;
	Vector2D direction;
	Vector2D velocity;
	int speed;
	float damping;
	void (*init)(GameObject *, Rect *, int, float);
	void (*update)(GameObject *);
	void (*cleanup)(GameObject *);
};

GameObject new_game_object(void);
void init_game_object(GameObject *, Rect *, int, float);
void update_game_object(GameObject *);
void cleanup_game_object(GameObject *);
void update_game_object_position(GameObject *);

#endif
