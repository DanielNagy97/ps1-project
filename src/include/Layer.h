#ifndef LAYER_H
#define LAYER_H

#include <GameObject.h>

typedef struct Layer Layer;

struct Layer
{
	GameObject *game_objects[10];
	int number_of_game_objects;
	void (*init)(Layer *);
	void (*add_game_object)(Layer *, GameObject *);
	void (*update)(Layer *);
	void (*cleanup)(Layer *);
};

Layer new_layer(void);
void init_layer(Layer *);
void add_game_object(Layer *, GameObject *);
void update_layer(Layer *);
void cleanup_layer(Layer *);

#endif
