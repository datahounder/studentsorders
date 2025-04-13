#include<stdio.h>
#include<stdlib.h>
#include"hof.h"
#include"k.h"

#define SIZEB 4

int main(){
	struct game Mgame;
	struct player list[10];
	Mgame.score = 0;
	int dy = 0;
	int dx = 1;
	
	for(int i = 0; i < SIZEB; i++){
		for(int j = 0; j < SIZEB; j++){
			Mgame.board[i][j] = ' ';
		}
	}

	add_random_tile(&Mgame);	
	render(Mgame);
	update(&Mgame, dy, dx);
	render(Mgame);	
	add_random_tile(&Mgame);	
	render(Mgame);
	update(&Mgame, dy, dx);
	render(Mgame);

	load(list);
	for(int i = 0; i < 10; i++){
		printf("%30s %10d\n", list[i].name, list[i].score);
	}
	int size = 0;
	struct player Mplayer = {
	    .name = "John",
	    .score = 100
	};

	add_player(list, &size, Mplayer);

	save(list, 4);

	printf("is won: %d\n", is_game_won(Mgame));


	printf("is move possible: %d\n", is_move_possible(Mgame));
// stdout: 0


	return EXIT_SUCCESS;
}
