#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"backpack.h"
#include"command.h"
#include"container.h"
#include"game.h"
#include"world.h"




int main(){
	
	// create rooms first
	struct room* home = create_room("home", "Nachadzas sa v chyzi svarneho suhaja. Na vychode sa nachadzaju dvere veduce z chyze von.");
	struct room* garden = create_room("", "Stojis pred chyzou a rozoznavas zahradku, ktora je znacne neudrziavana. este ze husty lesik na severe v porovnani so zahradkou nicim nevynika.");
	struct room* bathroom = create_room("bathroom", "Stojis pred chyzou a rozoznavas zahradku, ktora je znacne neudrziavana. este ze husty lesik na severe v porovnani so zahradkou nicim nevynika.");
	
	// set exits
	set_exits_from_room(home, NULL, NULL, garden, bathroom);
	set_exits_from_room(bathroom, NULL, NULL, home, NULL);
	
	// show room
	show_room(home);
	/*
	Nachadzas sa v chyzi svarneho suhaja. Na vychode sa nachadzaju dvere veduce z chyze von.
	Mozne vychody z miesnosti:
	    vychod
	*/

	// destroy rooms
	home = destroy_room(home);
	garden = destroy_room(garden);
	bathroom = destroy_room(bathroom);
	



	void delete_item_from_room(struct room* room, struct item* item);

	void add_item_to_room(struct room* room, struct item* item);

	struct item* get_item_from_room(const struct room* room, const char* name);





//command
	struct command* help = create_command("POMOC", "Zobrazi zoznam vsetkych prikazov", NULL, 0);


	help = destroy_command(help);

	
		
	// create parser first
	struct parser* parser = create_parser();
	/*
 	* Inside of the function create and add commands to the list of existing commands
 	*
 	*/

 	// parse input in the game loop
// 	char* input = "     VERZIA   ";
// 	struct command* cmd = parse_input(parser, input);
 	// cmd now should have reference to the command "VERZIA"

	// if input is unknown, parsing will return NULL
// 	char* unknown_input = "   CO JE V MIESTNOSTI?  ";
// 	cmd = parse_input(parser, unknown_input);
	
 	// cmd = NULL;


	// destroy parser at the end of game
	parser = destroy_parser(parser);

	struct command* parse_input(struct parser* parser, char* input);



//container
struct container* create_container(struct container* first, enum container_type type, void* entry);


//void* get_from_container_by_name(struct container* first, enum container_type type, const char* name);


struct container* delete_from_container(struct container* first, enum container_type type, void* entry);

//struct container* destroy_containers(struct container* first, enum container_type type);


//backpack
struct backpack* create_backpack(const int capacity);

struct backpack* destroy_backpack(struct backpack* backpack);

bool add_item_to_backpack(struct backpack* backpack, struct item* item);

void delete_item_from_backpack(struct backpack* backpack, struct item* item);

struct item* get_item_from_backpack(const struct backpack* backpack, char* name);

//game
void play_game(struct game* game);

struct game* create_game();

struct game* destroy_game(struct game* game);

void execute_command(struct game* game, struct command* command);

//item
struct item* create_item(char* name, char* description, unsigned int properties);

struct item* destroy_item(struct item* item);

//world
struct container* create_world();

struct container* add_room_to_world(struct container* world, struct room* room);

struct container* destroy_world(struct container* world);

struct room* get_room(struct container* world, char* name);




	return EXIT_SUCCESS;
}
