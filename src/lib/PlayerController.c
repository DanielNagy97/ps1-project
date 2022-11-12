#include <PlayerController.h>


PlayerController new_player_controller(void) {
	PlayerController player_controller;
	player_controller.init = &init_player_controller;
	player_controller.update = &update_player_controller;
	player_controller.cleanup = &cleanup_player_controller;

	return player_controller;
}

void init_player_controller(PlayerController* player_controller, GameObject* player_object) {
	player_controller->player_object = player_object;
}

void update_player_controller(PlayerController* player_controller) {
	GameObject* game_object = player_controller->player_object;
	update_pad();

	if(padCheck(Pad1Up)) {
		game_object->direction.y = -1;
		game_object->velocity.y = game_object->speed;
	}
	if(padCheck(Pad1Down)) {
		game_object->direction.y = 1;
		game_object->velocity.y = game_object->speed;
	}
	if(padCheck(Pad1Left)) {
		game_object->direction.x = -1;
		game_object->velocity.x = game_object->speed;
	}
	if(padCheck(Pad1Right)) {
		game_object->direction.x = 1;
		game_object->velocity.x = game_object->speed;
	}
}

void cleanup_player_controller(PlayerController* player_controller) {
	
}
