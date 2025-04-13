#include<stdio.h>
#include<stdlib.h>
#include "game.h"
#include "room.h"

void play_game(struct game* game){
	game->state = PLAYING;
	
	while(game->state == PLAYING){
		
		game->state = GAMEOVER;
		
	}

}


struct game* create_game(){
	struct game* ret_ptr = malloc(sizeof(struct game));
	ret_ptr->state = PLAYING;

	ret_ptr->parser = create_parser();
//CREATING ONE ROOM
	struct room* oneRoom = create_room("ROOM", "ROOM desc");
//CREATING ONE ROOM
    ret_ptr->world = create_container(NULL, ROOM, oneRoom);
	if(NULL != ret_ptr->world){
		//ret_ptr->current_room = ret_ptr->world->room;
		ret_ptr->current_room = get_from_container_by_name(ret_ptr->world, "ROOM");
	}
	else
		ret_ptr->current_room = NULL;

    ret_ptr->backpack = create_backpack(1);       
        
	return ret_ptr;
}


struct game* destroy_game(struct game* game){
	destroy_parser(game->parser);
	free(game->parser);

	destroy_containers(game->world);
	free(game->world);
	
	game->current_room = NULL;
	
	destroy_backpack(game->backpack);
	free(game->backpack);

	free(game);

	return NULL;
}


void execute_command(struct game* game, struct command* command){
	
	
}


