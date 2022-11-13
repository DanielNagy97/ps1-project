#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <Scene.h>
#include <PlayerController.h>

typedef struct GameEngine GameEngine;

struct GameEngine {
	Scene* scene;
	PlayerController* player_controller;
	void (* init)(GameEngine*, Scene*, PlayerController*);
	void (* update)(GameEngine*);
	void (* cleanup)(GameEngine*);
};

GameEngine new_game_engine(void);
void init_game_engine(GameEngine*, Scene*, PlayerController*);
void update_game_engine(GameEngine*);
void cleanup_game_engine(GameEngine*);

#endif