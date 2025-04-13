#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hof.h"
#include"k.h"




int load(struct player list[]){
	FILE *file = fopen(HOF_FILE, "rb");
		if(file == NULL ){
			fprintf(stderr, "No such file or directory.\n");
			return -1;
		}
	int size = 10;

	int i = -1;
	for(i = 0; i < size; i++){
        	int ret = fscanf(file, "%s %d\n", list[i].name, &list[i].score);
			if(ret == EOF) break;
	}

	fclose (file);

	return i;
}



bool save(const struct player list[], const int size){
	FILE *file = fopen("score.txt", "wb");
		if(file == NULL ){
			fprintf(stderr, "No such file or directory.\n");
			return false;
		}

	fclose (file);

	return true;

}


bool add_player(struct player list[], int* size, const struct player player){
	if(*size >= 10 || *size < 0) return false;
	strcpy(list[*size].name, player.name);
	list[*size].score = player.score;
	*size = *size + 1;
	return true;
}

