#ifndef SCENE_H
#define SCENE_H

#include <Layer.h>


typedef struct Scene Scene;

struct Scene {
	Layer* layers[3];
	int number_of_layers;
	void (* init)(Scene*);
	void (* add_layer)(Scene*, Layer*);
	void (* update)(Scene*);
	void (* cleanup)(Scene*);
};

Scene new_scene(void);
void init_scene(Scene*);
void add_layer(Scene*, Layer*);
void update_scene(Scene*);
void cleanup_scene(Scene*);

#endif