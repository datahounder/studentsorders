#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

#include "bmp.h"




char* reverse(const char* text){
	if(text == NULL)
	{
                return NULL;
        }

       
char buffer[strlen(text) + 1];

        strcpy(buffer, text);
       
 int length = strlen(buffer);

       
for(int i = length - 1, j = 0; 0 <= i; i--){
                if(j < length){
                        buffer[i] = text[j];
                }
                j++;
        }

        
for(int i = 0; i < length; i++){
                if(islower(buffer[i])){
                        buffer[i] = toupper(buffer[i]);
                }
        }


        
char* result = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy(result, buffer);

        return result;
	
}


char* vigenere_encrypt(const char* key, const char* text){
	if(text == NULL || key == NULL || text == "" || key == ""){
                return NULL;
        }

        
char buffer[strlen(text) + 1];
        char key_local[strlen(key) + 1];
        char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        strcpy(buffer, text);
        strcpy(key_local, key);

        
int length = strlen(buffer);
        
int key_length = strlen(key_local);
        
int alpha_length = strlen(alpha);


        
char key_new[length + 1];
        
char encrypt[length + 1];

        //to upper characters in buffer(text)
       
for(int i = 0; i < length; i++){
                if(islower(buffer[i])){
                        buffer[i] = toupper(buffer[i]);
                }
        }

        //to upper characters in key_local
        
for(int i = 0; i < key_length; i++){
                if(islower(key_local[i])){
                        key_local[i] = toupper(key_local[i]);
                }
        }

	//to create key_new
        
for(int i = 0, k = 1, l = 0; i < length; i++){
                if(buffer[i] != ' ' && i < key_length){
                        key_new[i] = key_local[i];
                }
                else if(i > key_length + k - 2 && buffer[i] != ' '){
                        int j = (i%(key_length + k - 1 + l));
                        key_new[i] = key_local[j];
                        if(j == key_length - 1){
                                l = l + key_length;
                        }
                }
                else if(buffer[i] == ' ' && i > key_length + k - 2){
                        key_new[i] = ' ';
                        k++;
                }
                else if(buffer[i] == ' ' && i < key_length + k){
                        key_new[i] = ' ';
                        i++;
                        while(i < key_length + k && buffer[i] != ' '){
                                key_new[i] = key_local[i - k];
                                i++;
                        }
                        k++;
                        i--;
                }
        }
        key_new[length] = '\0';

	//encrypt
       
 for(int i = 0, k = 0, l = 0; i < length; i++){
                for(int j = 0; j < alpha_length; j++){
                        if(isalpha(buffer[i])){
                                if(buffer[i] == alpha[j]){
                                        k = j;
                                }
                        }
                        if(isalpha(key_new[i])){
                                if(key_new[i] == alpha[j]){
                                        l = j;
                                }
                        }
                        if(isalpha(buffer[i])){
                                if( k + l < alpha_length){
                                        encrypt[i] = alpha[k + l];
                                }
                                else{
                                        encrypt[i] = alpha[(k + l) - alpha_length];
                                }
                        }
                        else{
                                encrypt[i] = buffer[i];
                                break;
                        }
                }
        }
        encrypt[length] = '\0';


        
char* result_1 = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy(result_1, encrypt);

        return result_1;

}

char* vigenere_decrypt(const char* key, const char* text){
	
if(text == NULL || key == NULL || text == "" || key == ""){
                return NULL;
        }

       
char buffer[strlen(text) + 1];
        
char key_local[strlen(key) + 1];
        
char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        strcpy(buffer, text);
        strcpy(key_local, key);

        int length = strlen(buffer);
        int key_length = strlen(key_local);
        int alpha_length = strlen(alpha);


        char key_new[length + 1];
        char encrypt[length + 1];

        //to upper characters in key_local
        for(int i = 0; i < key_length; i++){
                if(islower(key_local[i])){
                        key_local[i] = toupper(key_local[i]);
                }
        }

	//to create key_new
        for(int i = 0, k = 1, l = 0; i < length; i++){
                if(buffer[i] != ' ' && i < key_length){
                        key_new[i] = key_local[i];
                }
                else if(i > key_length + k - 2 && buffer[i] != ' '){
                        int j = (i%(key_length + k - 1 + l));
                        key_new[i] = key_local[j];
                        if(j == key_length - 1){
                                l = l + key_length;
                        }
                }
                else if(buffer[i] == ' ' && i > key_length + k - 2){
                        key_new[i] = ' ';
                        k++;
                }
                else if(buffer[i] == ' ' && i < key_length + k){
                        key_new[i] = ' ';
                        i++;
                        while(i < key_length + k && buffer[i] != ' '){
                                key_new[i] = key_local[i - k];
                                i++;
                        }
                        k++;
                        i--;
                }
        }
        key_new[length] = '\0';

	//decrypt
        for(int i = 0, k = 0, l = 0; i < length; i++){
                for(int j = 0; j < alpha_length; j++){
                        if(isalpha(buffer[i])){
                                if(buffer[i] == alpha[j]){
                                        k = j;
                                }
                        }
                        if(isalpha(key_new[i])){
                                if(key_new[i] == alpha[j]){
                                        l = j;
                                }
                        }
                        if(isalpha(buffer[i])){
                                if( k - l < alpha_length && k - l >= 0){
                                        encrypt[i] = alpha[k - l];
                                }
                                else{
                                        encrypt[i] = alpha[(k - l) + alpha_length];
                                }
                        }
                        else{
                                encrypt[i] = buffer[i];
                                break;
                        }
                }
        }
        encrypt[length] = '\0';


        char* result_2 = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy(result_2, encrypt);

        return result_2;

}


char* bit_encrypt(const char* text){
	if(text == NULL || text == ""){
                return NULL;
        }

        char buffer[strlen(text) + 1];

        strcpy(buffer, text);

        int length = strlen(buffer);
        int length_bit = 8;

        char bit[length_bit + 1];
        char pair_1[length_bit/2];
        char pair_2[length_bit/2];

        //Convert character into binary value
        for(int i = 0; i < length; i++){
                char c = buffer[i];
                for(int k = length_bit - 1; k >= 0; k--){
                        bit[k] = (c % 2) + '0';
                        c /= 2;
                }
                bit[length_bit] = '\0';


		//Create a pair
                for(int k = 0; k < length_bit/2; k++){
                        pair_1[k] = bit[k + 1];
                        pair_1[k + 1] = bit[k];
                        k++;
                }
                pair_1[length_bit/2] = '\0';

                for(int k = length_bit/2; k < length_bit; k++){
                        pair_2[k - length_bit/2] = bit[k];
                }
                pair_2[length_bit/2] = '\0';

                for(int k = 0; k < length_bit/2; k++){
                        if((pair_1[k] == '1' && pair_2[k] == '1') || (pair_1[k] == '0' && pair_2[k] == '0'))
                                pair_2[k] = '0';
                        else if((pair_1[k] == '1' && pair_2[k] == '0') || (pair_1[k] == '0' && pair_2[k] == '1'))
                                pair_2[k] = '1';
                }
                pair_2[length_bit/2] = '\0';

                for(int k = 0; k < length_bit; k++){
                        if(k < length_bit/2){
                                bit[k] = pair_1[k];
                        }
                        else if(k >= length_bit/2){
                                bit[k] = pair_2[k - length_bit/2];
                        }
                }
                bit[length_bit] = '\0';


                buffer[i] = strtol(bit, NULL, 2);
        }

	char* result = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy(result, buffer);

        return result;

}

char* bit_decrypt(const char* text){
	if(text == NULL || text == "" ||){
                return NULL;
        }

        char buffer[strlen(text) + 1];

        strcpy(buffer, text);

        int length = strlen(buffer);
        int length_bit = 8;

        char bit[length_bit + 1];
        char pair_1[length_bit/2];
        char pair_2[length_bit/2];


        //Convert character into binary value
        for(int i = 0; i < length; i++){
                unsigned char c = buffer[i];
                for(int k = length_bit - 1; k >= 0; k--){
                        bit[k] = (c % 2) + '0';
                        c /= 2;
                }
                bit[length_bit] = '\0';


		//Create a pair
                for(int k = 0; k < length_bit/2; k++){
                        pair_1[k] = bit[k];
                }
                pair_1[length_bit/2] = '\0';

                for(int k = length_bit/2; k < length_bit; k++){
                        pair_2[k - length_bit/2] = bit[k];
                }
                pair_2[length_bit/2] = '\0';

                for(int k = 0; k < length_bit/2; k++){
                        if((pair_1[k] == '1' && pair_2[k] == '1') || (pair_1[k] == '0' && pair_2[k] == '0'))
                                pair_2[k] = '0';
                        else if((pair_1[k] == '1' && pair_2[k] == '0') || (pair_1[k] == '0' && pair_2[k] == '1'))
                                pair_2[k] = '1';
                }
                pair_2[length_bit/2] = '\0';

                for(int k = 0; k < length_bit/2; k++){
                        pair_1[k] = bit[k + 1];
                        pair_1[k + 1] = bit[k];
                        k++;
                }
                pair_1[length_bit/2] = '\0';

                for(int k = 0; k < length_bit; k++){
                        if(k < length_bit/2){
                                bit[k] = pair_1[k];
                        }
                        else if(k >= length_bit/2){
                                bit[k] = pair_2[k - length_bit/2];
                        }
                }
                bit[length_bit] = '\0';


                buffer[i] = strtol(bit, NULL, 2);

	}

        char* result = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy(result, buffer);

        return result;
}

unsigned char* bmp_encrypt(const char* key, const char* text){
	if(text == NULL || key == NULL || text == "" || key == ""){
                return NULL;
        }

        char* reverse_1 = reverse(text);

        char* vigenere = vigenere_encrypt(key, reverse_1);

        char* bit = bit_encrypt(vigenere);

        char* result = (char*)malloc(sizeof(char) * (strlen(bit) + 1));
        strcpy(result, bit);

        free(reverse_1);
        reverse_1 = NULL;

        free(vigenere);
        vigenere = NULL;

        free(bit);
        bit = NULL;

        return result;

}

char* bmp_decrypt(const char* key, const unsigned char* text){
	if(text == NULL || key == NULL || text == "" || key == ""){
                
return NULL;
        }

        
char* bit = bit_decrypt(text);

        char* vigenere = vigenere_decrypt(key, bit);

        char* reverse_1 = reverse(vigenere);

        char* result = (char*)malloc(sizeof(char) * (strlen(reverse_1) + 1));
        strcpy(result, reverse_1);

        free(bit);
        bit = NULL;
        
	free(vigenere);
        vigenere = NULL;

        free(reverse_1);
        reverse_1 = NULL;


        return result;

}
                                                        
