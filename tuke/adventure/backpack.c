#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"backpack.h"

struct backpack* create_backpack(const int capacity){
	struct backpack* ret_back = malloc(sizeof(struct backpack));
	if(NULL == ret_back) return NULL;
	ret_back->capacity = capacity;
	ret_back->size = 0;
	ret_back->items = 0;	
	return ret_back;
}

void destroyBackpackItem(struct container *cont){
	if(cont->next != NULL)
		destroyBackpackItem(cont->next);
	free(cont);
}

struct backpack* destroy_backpack(struct backpack* backpack){
	if(backpack->items == NULL) return NULL;
	destroyBackpackItem(backpack->items);
	return NULL;
}


bool add_item_to_backpack(struct backpack* backpack, struct item* item){
	if(backpack == NULL || item == NULL) return NULL;
	if(backpack->size < backpack->capacity){
		if((item->properties & MOVABLE) > 0){
			struct container* itemInBack = create_container(backpack->items, ITEM, item);
			if(itemInBack != backpack->items){
				backpack->size++;
				return true;
			}
		}
	}
	return false;
}

int strcicmp_back(const char *first, const char *second){
	if(first == NULL || second == NULL) return -1;
	int diff = 0;
	for(; diff == 0 && *first != '\0' ;++first, ++second){
		diff = tolower((unsigned int)*first) - tolower((unsigned int)*second);			
	}
	return diff;
}

void delete_item_from_backpack(struct backpack* backpack, struct item* item){
	if(NULL == backpack || NULL == item) return;
	
	struct container *prev = backpack->items;
	struct container *cont = backpack->items;
	while(cont != NULL){
		if(cont->item->name == NULL) return;
		if(strcicmp_back(item->name, cont->item->name) == 0){
			prev->next = cont->next;
			free(cont);
			if(cont == backpack->items) backpack->items = cont->next;
			return;
		}
		prev = cont;
		cont = cont->next;
	}
}


struct item* get_item_from_backpack(const struct backpack* backpack, char* name){
	return get_from_container_by_name(backpack->items, name);
}


