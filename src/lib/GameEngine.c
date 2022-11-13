#include <GameEngine.h>


GameEngine new_game_engine(void) {
	GameEngine game_engine;
	game_engine.init = &init_game_engine;
	game_engine.update = &update_game_engine;
	game_engine.cleanup = &cleanup_game_engine;
	
	return game_engine;
}

void init_game_engine(GameEngine* game_engine,
					  Scene* scene,
					  PlayerController* player_controller) {
	game_engine->scene = scene;
	game_engine->player_controller = player_controller;
}

void update_game_engine(GameEngine* game_engine) {
	game_engine->scene->update(game_engine->scene);
	game_engine->player_controller->update(game_engine->player_controller);
}

void cleanup_game_engine(GameEngine* game_engine) {
	game_engine->scene->cleanup(game_engine->scene);
	game_engine->player_controller->cleanup(game_engine->player_controller);
	game_engine->scene = NULL;
	game_engine->player_controller = NULL;
	game_engine->init = NULL;
	game_engine->update = NULL;
	game_engine->cleanup = NULL;
}
