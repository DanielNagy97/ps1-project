#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <stdlib.h>
#include <libetc.h>
#include <controller.h>
#include <GameObject.h>

typedef struct PlayerController PlayerController;

struct PlayerController
{
	GameObject *player_object;
	void (*init)(PlayerController *, GameObject *);
	void (*update)(PlayerController *);
	void (*cleanup)(PlayerController *);
};

PlayerController new_player_controller(void);
void init_player_controller(PlayerController *, GameObject *);
void update_player_controller(PlayerController *);
void cleanup_player_controller(PlayerController *);

#endif