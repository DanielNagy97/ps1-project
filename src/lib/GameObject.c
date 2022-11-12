#include <GameObject.h>

GameObject new_game_object(void) {
	GameObject game_object;
	game_object.init = &init_game_object;
	game_object.update = &update_game_object;
	game_object.cleanup = &cleanup_game_object;
	
	return game_object;
}

void init_game_object(GameObject* game_object, Rect* rect, int speed) {
	Vector2D direction;
	Vector2D velocity;
	game_object->rect = rect;
	game_object->speed = speed;
	game_object->direction = direction;
	game_object->velocity = velocity;
}

void update_game_object(GameObject* game_object) {
	Rect* rect = game_object->rect;
	rect->update(rect);
}

void cleanup_game_object(GameObject* game_object) {

}

void update_game_object_position(GameObject* game_object, float damping) {
	int move_x;
	int move_y;
	int pos_x;
	int pos_y;
	Rect* rect = game_object->rect;
	
	Vector2D move_vector = {
		(game_object->direction.x * (game_object->velocity.x * 0.1)),
		(game_object->direction.y * (game_object->velocity.y * 0.1))
	};
	
	Vector2D new_position = {
		rect->position.x + move_vector.x,
		rect->position.y + move_vector.y
	};
	
	if(new_position.x <= 0) {
		new_position.x = 0;
	}
	else if(new_position.x + rect->width >= SCREEN_WIDTH) {
		new_position.x = SCREEN_WIDTH - rect->width;
	}
	if(new_position.y <= 0) {
		new_position.y = 0;
	}
	else if(new_position.y + rect->height >= SCREEN_HEIGHT) {
		new_position.y = SCREEN_HEIGHT - rect->height;
	}
	
	rect->position = new_position;
	
	game_object->velocity.x *= damping;
	game_object->velocity.y *= damping;
}