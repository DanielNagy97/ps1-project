#include <Layer.h>

Layer new_layer(void) {
	Layer layer;
	layer.init = &init_layer;
	layer.add_game_object = &add_game_object;
	layer.update = &update_layer;
	layer.cleanup = &cleanup_layer;
	
	return layer;
}

void init_layer(Layer* layer) {
	
}

void add_game_object(Layer* layer, GameObject* game_object) {
	
}

void update_layer(Layer* layer) {
	
}

void cleanup_layer(Layer* layer) {
	
}
