#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include"parser.h"


struct parser* create_parser(){
	struct parser* ret_ptr = malloc(sizeof(struct parser));
	struct command* basic_coms[17];
	basic_coms[0] = create_command("KONIEC", "Príkaz ukončí rozohratú hru. Nastaví príslušný stav hry.", "(QUIT)|(EXIT)", 2);
	basic_coms[1] = create_command("SEVER", "Presun do miestnosti nachádzajúcej sa na sever od aktuálnej. Zmení referenciu aktuálnej miestnosti.", "(S)", 1);
	basic_coms[2] = create_command("JUH", "Presun do miestnosti nachádzajúcej sa na juh od aktuálnej. Zmení referenciu aktuálnej miestnosti.", "(J)", 1);
	basic_coms[3] = create_command("VYCHOD", "Presun do miestnosti nachádzajúcej sa na východ od aktuálnej. Zmení referenciu aktuálnej miestnosti.", "(V)", 1);
	basic_coms[4] = create_command("ZAPAD", "Presun do miestnosti nachádzajúcej sa na východ od aktuálnej. Zmení referenciu aktuálnej miestnosti.", "(Z)", 1);
	basic_coms[5] = create_command("ROZHLIADNI SA", "Príkaz vypíše aktuálne informácie o miestnosti, v ktorej sa hráč práve nachádza.", "", 0);
	basic_coms[6] = create_command("PRIKAZY", "Príkaz vypíše na obrazovku zoznam všetkých príkazov, ktoré hra poskytuje.", "(HELP)|(POMOC)", 2);
	basic_coms[7] = create_command("VERZIA", "Príkaz zobrazí číslo verzie hry, ľubovoľný sprievodný text a meno a priezvisko autora s kontaktom (e-mailová adresa, webová stránka).", "", 0);
	basic_coms[8] = create_command("RESTART", "Znovu spustí hru od začiatku. Zmení stav hry na požadovaný.", "", 0);
	basic_coms[9] = create_command("O HRE", "Príkaz zobrazí krátky text, ktorý poslúži ako úvod do príbehu. Ako dobrý začiatok sa javí známy text: Kde bolo tam bolo, …", "(ABOUT)", 1);
	basic_coms[10] = create_command("VEZMI", "Vloží predmet z miestnosti do batohu. Príkaz má jeden povinný parameter, ktorým je názov predmetu. Ak predmet nebude zadaný, program vypíše na obrazovku vhodnú hlášku (napr. Neviem, čo chceš vziať.).", "", 0);
	basic_coms[11] = create_command("POLOZ", "Položí predmet z batohu do miestnosti. Príkaz má jeden povinný parameter, ktorým je názov predmetu. Ak predmet nebude zadaný, program vypíše na obrazovku vhodnú hlášku (napr. Neviem, čo chceš položiť.)", "", 0);
	basic_coms[12] = create_command("INVENTAR", "Zobrazí obsah hráčovho batohu.", "(I)", 1);
	basic_coms[13] = create_command("POUZI", "Použije predmet z batohu alebo miestnosti. Príkaz má jeden povinný parameter, ktorým je názov predmetu. Ak predmet nebude zadaný, program vypíše na obrazovku vhodnú hlášku (napr. Neviem, čo chceš použiť.).", "", 0);
	basic_coms[14] = create_command("PRESKUMAJ", "Vypíše opis predmetu, ktorý sa musí nachádzať v miestnosti alebo batohu. Príkaz má jeden povinný parameter, ktorým je názov predmetu. Ak predmet nebude zadaný alebo sa nenájde v batohu alebo v miestnosti, program vypíše na obrazovku vhodnú hlášku (napr. Neviem, čo chceš preskúmať.).", "", 0);
	basic_coms[15] = create_command("NAHRAJ", "Príkaz zabezpečí nahratie uloženej pozície hry z disku. Voliteľným parametrom je cesta k súboru.", "(LOAD)", 1);
	basic_coms[16] = create_command("ULOZ", "Príkaz uloží stav rozohratej hry na disk. Voliteľným parametrom je cesta k súboru.", "(SAVE)", 1);
	ret_ptr->commands = create_container(NULL, COMMAND, basic_coms[0]);
	if(NULL == ret_ptr->commands){
		free(ret_ptr);
		return NULL;
	}
	ret_ptr->commands = create_container(ret_ptr->commands, COMMAND, basic_coms[1]);
	ret_ptr->commands = create_container(ret_ptr->commands, COMMAND, basic_coms[2]);
	ret_ptr->commands = create_container(ret_ptr->commands, COMMAND, basic_coms[3]);
	ret_ptr->commands = create_container(ret_ptr->commands, COMMAND, basic_coms[4]);
	ret_ptr->commands = create_container(ret_ptr->commands, COMMAND, basic_coms[5]);
	ret_ptr->commands = create_container(ret_ptr->commands, COMMAND, basic_coms[6]);
	ret_ptr->commands = create_container(ret_ptr->commands, COMMAND, basic_coms[7]);
	ret_ptr->commands = create_container(ret_ptr->commands, COMMAND, basic_coms[8]);
	ret_ptr->commands = create_container(ret_ptr->commands, COMMAND, basic_coms[9]);
	ret_ptr->commands = create_container(ret_ptr->commands, COMMAND, basic_coms[10]);
	ret_ptr->commands = create_container(ret_ptr->commands, COMMAND, basic_coms[11]);
	ret_ptr->commands = create_container(ret_ptr->commands, COMMAND, basic_coms[12]);
	ret_ptr->commands = create_container(ret_ptr->commands, COMMAND, basic_coms[13]);
	ret_ptr->commands = create_container(ret_ptr->commands, COMMAND, basic_coms[15]);
	ret_ptr->commands = create_container(ret_ptr->commands, COMMAND, basic_coms[16]);
	
	ret_ptr->history = create_container(NULL, COMMAND, basic_coms[9]);
	if(ret_ptr->history == NULL){
		free(ret_ptr);
		return NULL;
	}
	return ret_ptr;
}


struct parser* destroy_parser(struct parser* parser){
	destroy_containers(parser->commands);
	
	destroy_containers(parser->history);

	free(parser);
	
	return NULL;
}


struct command* parse_input(struct parser* parser, char* input){
	if(parser == NULL || input == NULL) return NULL;
	return get_from_container_by_name(parser->commands, input);
	

}

