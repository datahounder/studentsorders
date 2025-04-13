#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"container.h"

void container_Append_to_End(struct container* first, struct container* append){
	struct container* cont = first;
	while(cont->next != NULL)
		cont = cont->next;
	cont->next = append;
}

void container_Add_Entry(struct container* cont, void* entry){
	switch(cont->type){
		case ROOM:
			cont->room = entry;
		break;
		case ITEM:
			cont->item = entry;
		break;
		case COMMAND:
			cont->command = entry;
		break;
		case TEXT:
			cont->text = entry;
		break;
		default:
		break;
	}
}

struct container* create_container(struct container* first, enum container_type type, void* entry){
	if(NULL == entry) return remove_container(NULL, NULL); //hadze chybu remove_container not used!!!
	
	struct container* ret_pointer = malloc(sizeof(struct container));
	ret_pointer->type = type;
	ret_pointer->next = NULL;
	container_Add_Entry(ret_pointer, entry);
	if(NULL == first) return ret_pointer;
	
	if(type != first->type){
		free(ret_pointer);
		return NULL;
	}
	container_Append_to_End(first, ret_pointer);
	return ret_pointer;
}

void container_Kill_Entry(struct container* cont){
	switch(cont->type){
		case ROOM:
			destroy_room(cont->room);
		break;
		case ITEM:
			destroy_item(cont->item);
		break;
		case COMMAND:
			destroy_command(cont->command);
		break;
		case TEXT:
			free(cont->text);
		break;
		default:
		break;
	}
}

void container_kill(struct container* cont){
	if(cont == NULL) return;
	if(cont->next != NULL)
		container_kill(cont->next);
	container_Kill_Entry(cont);
	free(cont);
	cont = NULL;
}

struct container* destroy_containers(struct container* first){
	if(NULL == first) return NULL;
	container_kill(first);	
	
//struct container* destroy_containers(struct container* first, enum container_type type){
	//first->type = type;	
/*
	free(first);
	first = NULL;
*/
	return NULL;
}

int strcicmp(const char *first, const char *second){
	if(first == NULL || second == NULL) return -1;
	int diff = 0;
	for(; diff == 0 && *first != '\0' ;++first, ++second){
		diff = tolower((unsigned int)*first) - tolower((unsigned int)*second);			
	}
	return diff;
}

char* get_UnionName(struct container *cont){
	switch(cont->type){
		case ROOM:
			if(cont->room == NULL) return NULL;
			return cont->room->name;
		break;
		case ITEM:
			if(cont->item == NULL) return NULL;
			return cont->item->name;
		break;
		case COMMAND:
			if(cont->command == NULL) return NULL;
			return cont->command->name;
		break;
		case TEXT:
			return cont->text;
		break;
		default:
		break;
	}
	return NULL;
}

void* get_from_container_by_name(struct container *first, const char *name){
	if(first == NULL || name == NULL) return NULL;
	
	struct container *cont = first;
	while(cont != NULL){
		char * item_name = get_UnionName(cont);
		if(item_name == NULL){
			cont = cont->next;
			continue;
		}
		if(strcicmp(name, item_name) == 0)
			return cont;
		cont = cont->next;
	}
	return NULL;
/*
//void* get_from_container_by_name(struct container* first, enum container_type type, const char* name){
	if(first == NULL || name == NULL){
		return NULL;
	}

	//first->type = type;

	char buffer[30];
	strcpy(buffer, name);
	for(int i = 0; buffer[i] != '\0'; i++){
		if(islower(buffer[i])){
			buffer[i] = (char)toupper(buffer[i]);
		}
	}
	
	
//	ROOM, ITEM, COMMAND, TEXT	

	char room[] = "ROOM";
	char command[] = "COMMAND";
	char item[] = "ITEM";
	char text[] = "TEXT";

	if(room == buffer){
		type = ROOM;
		first->type = type;
	}
	else if(command == buffer){
		type = COMMAND;
		first->type = type;
	}
	else if(item == name){
		type = ITEM;
		first->type = type;
	}
	else if(text == name){
		type = TEXT;
		first->type = type;
	}
	else{
		return NULL;
	}

	return first;
	*/
}

char* getNameFromUnion(void *entry, enum container_type type){
	switch(type){
		case ROOM:
			return ((struct room*)entry)->name;
		break;
		case ITEM:
			return ((struct item*)entry)->name;
		break;
		case COMMAND:
			return ((struct command*)entry)->name;
		break;
		case TEXT:
			return (char*)entry;
		break;
		default:
		break;
	}
	return NULL;
}

struct container* remove_container(struct container *first, void *entry){
	if(NULL == first || entry == NULL) return first;
	
	struct container *prev = first;
	struct container *cont = first;
	while(cont != NULL){
		if(strcicmp(get_UnionName(cont), getNameFromUnion(entry, cont->type)) == 0){
			prev->next = cont->next;
			free(cont);
			if(cont == first) return NULL;
			return prev;
		}
		prev = cont;
		cont = cont->next;
	}
	
	return first;
}
