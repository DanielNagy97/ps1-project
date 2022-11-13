#include <Layer.h>

Layer new_layer(void)
{
	Layer layer;
	layer.number_of_game_objects = 0;
	layer.init = &init_layer;
	layer.add_game_object = &add_game_object;
	layer.update = &update_layer;
	layer.cleanup = &cleanup_layer;

	return layer;
}

void init_layer(Layer *layer)
{
}

void add_game_object(Layer *layer, GameObject *game_object)
{
	layer->game_objects[layer->number_of_game_objects] = game_object;
	layer->number_of_game_objects++;
}

void update_layer(Layer *layer)
{
	int i;
	for (i = 0; i < layer->number_of_game_objects; i++)
	{
		layer->game_objects[i]->update(layer->game_objects[i]);
	}
}

void cleanup_layer(Layer *layer)
{
	int i;
	for (i = 0; i < layer->number_of_game_objects; i++)
	{
		layer->game_objects[i]->cleanup(layer->game_objects[i]);
		layer->game_objects[i] = NULL;
	}
	layer->number_of_game_objects = 0;
	layer->init = NULL;
	layer->add_game_object = NULL;
	layer->update = NULL;
	layer->cleanup = NULL;
}
