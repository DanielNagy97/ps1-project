#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <Scene.h>


typedef struct GameEngine GameEngine;

struct GameEngine {
	Scene* scene;
	void (* init)(GameEngine*);
	void (* add_scene)(GameEngine*, Scene*);
	void (* update)(GameEngine*);
	void (* cleanup)(GameEngine*);
};

GameEngine new_game_engine(void);
void init_game_engine(GameEngine*);
void add_scene(GameEngine*, Scene*);
void update_game_engine(GameEngine*);
void cleanup_game_engine(GameEngine*);

#endif