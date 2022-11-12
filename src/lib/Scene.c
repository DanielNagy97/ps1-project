#include <Scene.h>

Scene new_scene(void) {
	Scene scene;
	scene.init = &init_scene;
	scene.add_layer = &add_layer;
	scene.update = &update_scene;
	scene.cleanup = &cleanup_scene;
	
	return scene;
}

void init_scene(Scene* scene) {
	
}

void add_layer(Scene* scene, Layer* layer) {
	
}

void update_scene(Scene* scene) {
	
}

void cleanup_scene(Scene* scene) {
	
}