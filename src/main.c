#include <main.h>


int main() {
	char text[100];
	Rect rect = new_rect();
	Rect rect_npc = new_rect();
	GameObject game_object = new_game_object();
	GameObject npc_object = new_game_object();
	Layer layer = new_layer();
	Scene scene = new_scene();
	PlayerController player_controller = new_player_controller();
	GameEngine game_engine = new_game_engine();

	Vector2D position = {100, 60};
	RGBColor color = {52, 235, 131};
	
	Vector2D position_npc = {180, 150};
	RGBColor color_npc = {90, 135, 31};
	
	rect.init(&rect, position, 40, 20, color);
	rect_npc.init(&rect_npc, position_npc, 60, 60, color_npc);
	game_object.init(&game_object, &rect, 40, 0.98);
	npc_object.init(&npc_object, &rect_npc, 40, 0.98);
	layer.add_game_object(&layer, &game_object);
	layer.add_game_object(&layer, &npc_object);
	scene.add_layer(&scene, &layer);
	player_controller.init(&player_controller, &game_object);
	
	// TODO: build the scene from file (csv or something)
	game_engine.init(&game_engine, &scene, &player_controller);

	initialize();
	
	while (1) {
		game_engine.update(&game_engine);

		sprintf(text, "Hello world!\n\ndir_x: %d(%d)\n\ndir_y: %d(%d)\n\n object in layer:%d\n\nNellyke 2022",
				game_engine.scene->layers[0]->game_objects[0]->direction.x, game_engine.scene->layers[0]->game_objects[0]->velocity.x,
				game_engine.scene->layers[0]->game_objects[0]->direction.y, game_engine.scene->layers[0]->game_objects[0]->velocity.y,
				game_engine.scene->layers[0]->number_of_game_objects);
		
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
