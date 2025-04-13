#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"item.h"


struct item* create_item(char* name, char* description, unsigned int properties){
	if(NULL == name || NULL == description) return NULL;
	if(strlen(name) == 0 || strlen(description) == 0) return NULL;
	struct item* ret_ptr = malloc(sizeof(struct item));
	ret_ptr->name = name;
	ret_ptr->description = description;
	ret_ptr->properties = properties;
	return ret_ptr;
}


struct item* destroy_item(struct item* item){
	free(item->name);
	free(item->description);
	free(item);
	return NULL;
}
