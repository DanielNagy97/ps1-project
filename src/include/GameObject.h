#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <Rect.h>


typedef struct GameObject GameObject;

struct GameObject {
	Rect* rect;
	void (* init)(GameObject*);
	void (* update)(GameObject*);
	void (* cleanup)(GameObject*);
};

GameObject new_game_object(void);
void init_game_object(GameObject*);
void update_game_object(GameObject*);
void cleanup_game_object(GameObject*);

#endif