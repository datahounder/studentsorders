#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "k.h"

#define SIZEB 4

void add_random_tile(struct game *game){
    int row, col;
    // find random, but empty tile
    do{
        row = rand() % 4;
        col = rand() % 4;
    }while(game->board[row][col] != ' ');

    // place to the random position 'A' or 'B' tile
    int tile = 'A' + (rand() % 2);
    game->board[row][col] = (char)tile;
}

void render(const struct game game){
	printf("\n");
	

	for(int k = 0; k < SIZEB; k++){
        	for(int i = 0; i < SIZEB; i++){
	                if(i != SIZEB - 1)
                        	printf("+---");
                	else
        	                printf("+---+");
	        }
        	printf("\n");
	
	        for(int i = 0; i < SIZEB; i++){
                	if(i != SIZEB - 1)
        	                printf("| %c ", game.board[k][i]);
	                else
                	        printf("| %c |", game.board[k][i]);
        	}
	        printf("\n");
	}

        for(int i = 0; i < SIZEB; i++){
                if(i != SIZEB - 1)
                        printf("+---");
                else
                        printf("+---+");
        }
        printf("\n");

}


bool is_game_won(const struct game game){
        int state = 0;

        for(int i = 0; i < SIZEB; i++){
                for(int j = 0; j < SIZEB; j++){
                        if(game.board[i][j] == 'K')
                                state = 1;
                }
        }


        if(state == 1)
                return true;
        else
                return false;


}


bool is_move_possible(const struct game game){
	int state = 0;

        for(int i = 0; i < SIZEB; i++){
                for(int j = 0; j < SIZEB; j++){
                        if(game.board[i][j] == ' ' || game.board[i][j] == game.board[i][j + 1] || game.board[i][j] == game.board[i + 1][j])
                                state = 1;
                }
        }


        if(state == 1)
                return true;
        else
                return false;

}

bool update(struct game *game, int dy, int dx){
	int state = 1;

	char point[] = "ABCDEFGHIJK";
	
	if(dx == 1 && dy == 0){
		for(int a = 0; point[a] != '\0'; a++){
			int i;
			for(i = 0; i < SIZEB; i++){
				int j = SIZEB - 1;
				while(j == SIZEB - 1){
					if(game->board[i][j] == ' ' && game->board[i][j - 1] == ' ' && game->board[i][j - 2] == ' ' && game->board[i][j - 3] == ' '){
						break;
					}
					if(game->board[i][j] == point[a] && game->board[i][j - 1] == ' ' && game->board[i][j - 2] == ' ' && game->board[i][j - 3] == ' '){
						game->board[i][j] = point[a];
						break;
					}
					if(game->board[i][j] == ' ' && game->board[i][j - 1] == point[a] && game->board[i][j - 2] == ' ' && game->board[i][j - 3] == ' '){
						game->board[i][j] = point[a];
						game->board[i][j - 1] = ' ';
						break;
					}
					if(game->board[i][j] == ' ' && game->board[i][j - 1] == ' ' && game->board[i][j - 2] == point[a] && game->board[i][j - 3] == ' '){
						game->board[i][j] = point[a];
						game->board[i][j - 2] = ' ';
						break;
					}
					if(game->board[i][j] == ' ' && game->board[i][j - 1] == ' ' && game->board[i][j - 2] == ' ' && game->board[i][j - 3] == point[a]){
						game->board[i][j] = point[a];
						game->board[i][j - 3] = ' ';
						break;
					}
					if(game->board[i][j] == point[a] && game->board[i][j - 1] == point[a] && game->board[i][j - 2] == ' ' && game->board[i][j - 3] == ' '){
						game->board[i][j] = point[a + 1];
						game->board[i][j] = ' ';
						game->board[i][j - 1] = ' ';
						break;
					}
					if(game->board[i][j] == ' ' && game->board[i][j - 1] == point[a] && game->board[i][j - 2] == point[a] && game->board[i][j - 3] == ' '){
						game->board[i][j] = point[a + 1];
						game->board[i][j - 1] = ' ';
						game->board[i][j - 2] = ' ';
						break;
					}
					if(game->board[i][j] == ' ' && game->board[i][j - 1] == ' ' && game->board[i][j - 2] == point[a] && game->board[i][j - 3] == point[a]){
						game->board[i][j] = point[a + 1];
						game->board[i][j - 2] = ' ';
						game->board[i][j - 3] = ' ';
						break;
					}
					if(game->board[i][j] == point[a] && game->board[i][j - 1] == ' ' && game->board[i][j - 2] == point[a] && game->board[i][j - 3] == ' '){
						game->board[i][j] = point[a + 1];
						game->board[i][j - 2] = ' ';
						break;
					}
					if(game->board[i][j] == ' ' && game->board[i][j - 1] == point[a] && game->board[i][j - 2] == ' ' && game->board[i][j - 3] == point[a]){
						game->board[i][j] = point[a + 1];
						game->board[i][j - 1] = ' ';
						game->board[i][j - 3] = ' ';
						break;
					}
					if(game->board[i][j] == point[a] && game->board[i][j - 1] == ' ' && game->board[i][j - 2] == ' ' && game->board[i][j - 3] == point[a]){
						game->board[i][j] = point[a + 1];
						game->board[i][j - 3] = ' ';
						break;
					}
					if(game->board[i][j] == ' ' && game->board[i][j - 1] == point[a] && game->board[i][j - 2] == point[a] && game->board[i][j - 3] == point[a]){
						game->board[i][j] = point[a + 1];
						game->board[i][j - 1] = point[a];
						game->board[i][j - 2] = ' ';
						game->board[i][j - 3] = ' ';
						break;
					}
					if(game->board[i][j] == point[a] && game->board[i][j - 1] == ' ' && game->board[i][j - 2] == point[a] && game->board[i][j - 3] == point[a]){
						game->board[i][j] = point[a + 1];
						game->board[i][j - 1] = point[a];
						game->board[i][j - 2] = ' ';
						game->board[i][j - 3] = ' ';
						break;
					}
					if(game->board[i][j] == point[a] && game->board[i][j - 1] == point[a] && game->board[i][j - 2] == ' ' && game->board[i][j - 3] == point[a]){
						game->board[i][j] = point[a + 1];
						game->board[i][j - 1] = point[a];
						game->board[i][j - 3] = ' ';
						break;
					}
					if(game->board[i][j] == point[a] && game->board[i][j - 1] == point[a] && game->board[i][j - 2] == point[a] && game->board[i][j - 3] == ' '){
						game->board[i][j] = point[a + 1];
						game->board[i][j - 1] = point[a];
						game->board[i][j - 2] = ' ';
						break;
					}
					if(game->board[i][j] == point[a] && game->board[i][j - 1] == point[a] && game->board[i][j - 2] == point[a] && game->board[i][j - 3] == point[a]){
						game->board[i][j] = point[a + 1];
						game->board[i][j - 1] = point[a + 1];
						game->board[i][j - 2] = ' ';
						game->board[i][j - 3] = ' ';
						break;
					}
					if(game->board[i][j] == point[a] && game->board[i][j - 1] == point[a] && game->board[i][j - 2] != point[a] && game->board[i][j - 3] == ' '){
						game->board[i][j] = point[a + 1];
						game->board[i][j - 1] = game->board[i][j - 2];
						game->board[i][j - 2] = ' ';
						break;
					}
					if(game->board[i][j] == point[a] && game->board[i][j - 1] == point[a] && game->board[i][j - 2] == ' ' && game->board[i][j - 3] != point[a]){
						game->board[i][j] = point[a + 1];
						game->board[i][j - 1] = game->board[i][j - 3];
						game->board[i][j - 3] = ' ';
						break;
					}
					if(game->board[i][j] == point[a] && game->board[i][j - 1] == ' ' && game->board[i][j - 2] == point[a] && game->board[i][j - 3] != point[a]){
						game->board[i][j] = point[a + 1];
						game->board[i][j - 1] = game->board[i][j - 3];
						game->board[i][j - 2] = ' ';
						game->board[i][j - 3] = ' ';
						break;
					}
					if(game->board[i][j] == ' ' && game->board[i][j - 1] == point[a] && game->board[i][j - 2] == point[a] && game->board[i][j - 3] != point[a]){
						game->board[i][j] = point[a + 1];
						game->board[i][j - 1] = game->board[i][j - 3];
						game->board[i][j - 2] = ' ';
						game->board[i][j - 3] = ' ';
						break;
					}
					if(game->board[i][j] == point[a] && game->board[i][j - 1] == point[a] && game->board[i][j - 2] != point[a] && game->board[i][j - 3] != point[a]){
						game->board[i][j] = point[a + 1];
						if(game->board[i][j - 2] == game->board[i][j - 3] && game->board[i][j - 2] == point[a + 1]){
							game->board[i][j - 1] = point[a + 2];
							game->board[i][j - 2] = ' ';
						}
						else{
							game->board[i][j - 1] = game->board[i][j - 2];
							game->board[i][j - 2] = game->board[i][j - 3];
						}	
						game->board[i][j - 3] = ' ';
						break;
					}
					j = 0;
				}
			}
			if(i == 3){
				break;
			}
		}
	}
	
	if(state == 1)
		return true;
	else
		return false;

}



