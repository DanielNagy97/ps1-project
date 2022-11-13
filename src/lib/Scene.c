#include <Scene.h>


Scene new_scene(void) {
	Scene scene;
	scene.number_of_layers = 0;
	scene.init = &init_scene;
	scene.add_layer = &add_layer;
	scene.update = &update_scene;
	scene.cleanup = &cleanup_scene;
	
	return scene;
}

void init_scene(Scene* scene) {
	
}

void add_layer(Scene* scene, Layer* layer) {
	scene->layers[scene->number_of_layers] = layer;
	scene->number_of_layers++;
}

void update_scene(Scene* scene) {
	int i;
	for (i = 0; i < scene->number_of_layers; i++) {
		scene->layers[i]->update(scene->layers[i]);
	}
}

void cleanup_scene(Scene* scene) {
	int i;
	for (i = 0; i < scene->number_of_layers; i++) {
		scene->layers[i]->cleanup(scene->layers[i]);
		scene->layers[i] = NULL;
	}
	scene->number_of_layers = 0;
	scene->init = NULL;
	scene->add_layer = NULL;
	scene->update = NULL;
	scene->cleanup = NULL;
}