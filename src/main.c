#include <main.h>

void initialize();

int main() {
	char text[100];
	GameObject game_object = new_game_object();
	PlayerController player_controller = new_player_controller();
	Rect rect = new_rect();
	Vector2D position = {100, 60};
	RGBColor color = {52, 235, 131};
	
	rect.init(&rect, position, 40, 20, color);
	game_object.init(&game_object, &rect, 40);
	player_controller.init(&player_controller, &game_object);

	initialize();
	
	while (1) {
		game_object.update(&game_object);
		player_controller.update(&player_controller);

		sprintf(text, "Hello world!");
		FntPrint(text);

		display();
	}

	return 0;
}

void initialize() {
	init_graphics();
	init_pad();
	init_debugfont();
}
