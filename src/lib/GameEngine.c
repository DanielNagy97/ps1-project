#include <GameEngine.h>

GameEngine new_game_engine(void)
{
	GameEngine game_engine;
	game_engine.init = &init_game_engine;
	game_engine.update = &update_game_engine;
	game_engine.cleanup = &cleanup_game_engine;

	return game_engine;
}

void init_game_engine(GameEngine *game_engine,
					  Scene *scene,
					  PlayerController *player_controller)
{
	game_engine->scene = scene;
	game_engine->player_controller = player_controller;
}

void update_game_engine(GameEngine *game_engine)
{
	game_engine->scene->update(game_engine->scene);
	game_engine->player_controller->update(game_engine->player_controller);
	show_debug_text(game_engine);
}

void cleanup_game_engine(GameEngine *game_engine)
{
	game_engine->scene->cleanup(game_engine->scene);
	game_engine->player_controller->cleanup(game_engine->player_controller);
	game_engine->scene = NULL;
	game_engine->player_controller = NULL;
	game_engine->init = NULL;
	game_engine->update = NULL;
	game_engine->cleanup = NULL;
}

void show_debug_text(GameEngine *game_engine)
{
	char text[100];
	Layer *layer = game_engine->scene->layers[0];
	GameObject *game_object = layer->game_objects[0];
	GameObject *game_object2 = layer->game_objects[1];
	BoundingBox2D box1 = game_object->rect->bounding_box;
	BoundingBox2D box2 = game_object2->rect->bounding_box;

	sprintf(text, "Hello world!\n\nmin: %d, %d\n\nmax: %d, %d\n\nCollosion:%d\n\nNellyke 2022",
			box1.min_point.x, box1.min_point.y,
			box1.max_point.x, box1.max_point.y,
			box1.check_overlapping(&box1, &box2));

	FntPrint(text);
}