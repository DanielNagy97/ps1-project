#include <main.h>


int main() {
	Rect rects[] = {new_rect(), new_rect()};
	GameObject game_objects[] = {new_game_object(), new_game_object()};
	Vector2D positions[] = {{100, 60}, {180, 150}};
	RGBColor colors[] = {{52, 235, 131}, {90, 135, 31}};
	Dimensions2D dimensions[] = {{40, 20,}, {60, 60}};
	Layer layer = new_layer();
	Scene scene = new_scene();
	PlayerController player_controller = new_player_controller();
	GameEngine game_engine = new_game_engine();
	int i;
	
	for (i = 0; i < 2; i++) {
		rects[i].init(&rects[i], positions[i], dimensions[i], colors[i]);
		game_objects[i].init(&game_objects[i], &rects[i], 40, 0.98);
		layer.add_game_object(&layer, &game_objects[i]);
	}
	
	scene.add_layer(&scene, &layer);
	player_controller.init(&player_controller, &game_objects[0]);
	
	// TODO: build the scene from file (csv or something)
	game_engine.init(&game_engine, &scene, &player_controller);

	initialize();
	
	while (1) {
		game_engine.update(&game_engine);

		display();
	}

	return 0;
}

void initialize(void) {
	init_graphics();
	init_pad();
	init_debugfont();
}

