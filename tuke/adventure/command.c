#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"command.h"


struct command* create_command(char* name, char* description, char* pattern, size_t nmatch){
	if(name == NULL || strlen(name) == 0){
		return NULL;
	}

	if(description == NULL || strlen(description) == 0){
		return NULL;
	}

	struct command* new_command = malloc(sizeof(struct command));
	
	new_command->name = malloc(sizeof(char)*strlen(name)+1);
	strcpy(new_command->name, name);
	
	new_command->description = malloc(sizeof(char)*strlen(description)+1);
	strcpy(new_command->description, description);
	
	new_command->nmatch = nmatch;
	new_command->groups = &pattern;

	return new_command;
}


struct command* destroy_command(struct command* command){
	free(command->name);
	free(command->description);
	free(command);		

	return NULL;
}


