#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include "playfair.h"

#define MAXSTR "ABCDEFGHIJKLMNOPQRSTUVXYZ"

char* playfair_encrypt(const char* key, const char* text){

    if( key==NULL || text==NULL){
        return NULL;
    }


    bool right = true;
    size_t sof_key = strlen(key);
    char *mykey = (char*)calloc(sof_key+1,sizeof(char));

    for(int i=0; i<sof_key;i++){
        if(isalpha(key[i])){
            right=false;
        }

        if(!isalpha(key[i]) && key[i]!=' '){
            free(mykey);
            return NULL ;
        }

        mykey[i]=toupper(key[i]);
        if(mykey[i]=='W'){
            mykey[i]='V';
        }
    }

    if(right){
        free(mykey);
        return NULL;
    }
    mykey[sof_key]='\0';

    int diff = 0, leng = 0;
    size_t sof_text = strlen(text);
    char *mytext = (char*)calloc(2*sof_text+1,sizeof(char));

    for(int i=0; i<sof_text;i++){
        mytext[i+diff]=toupper(text[i]);
        leng++;

        if(mytext[i+diff]==' '){
            diff--;
            leng--;
        }else{
            if(mytext[i+diff]=='W'){
                mytext[i+diff]='V';
            }
            if(( i+diff )% 2 == 1){
                if(mytext[i+diff]==mytext[i-1+diff] && mytext[i+diff]!='X' && mytext[i+diff]!=' '){
                    mytext[i+1+diff]=mytext[i+diff];
                    mytext[i+diff]='X';
                    diff++;
                    leng++;
                }
            }
        }
    }

   if(leng % 2 == 1){
        mytext[leng]='X';
        leng++;
    }
    mytext[leng]='\0';

    char table[5][5];
    char alpha[26];
    strcpy(alpha, MAXSTR);

    int count = -1;

    for(int i = 0 ; i<5; i++){
        for(int j = 0; j<5; j++){
            count++;
                if((count)<sof_key){
                    table[i][j]=' ';
                    for(int x=0; x < 25 ; x++){
                        if(alpha[x]==mykey[count]){
                            alpha[x]=' ';
                            table[i][j]=mykey[count];
                        }
                    }
                    if(table[i][j]==' '){
                        if(j!=0){
                            j--;
                        }else{
                            i--;
                            j=4;
                        }
                    }
                }else{
                    for(int x=0; x < 25 ; x++){
                        if(alpha[x]!=' '){
                            table[i][j]=alpha[x];
                            alpha[x]=' ';
                            break;
                    }
                }
            }
        }
    }

    char *cipher = (char*) calloc(leng+leng/2,sizeof(char));

    for(int i=0;i <leng;i=i+2){
        for(int x_pos_a = 0 ; x_pos_a<5; x_pos_a++){
            for(int y_pos_a = 0; y_pos_a<5; y_pos_a++){
                if(mytext[i]==table[x_pos_a][y_pos_a]){
                    for(int x_pos_b = 0 ; x_pos_b<5; x_pos_b++){
                        for(int y_pos_b = 0; y_pos_b<5; y_pos_b++){
                            if (mytext[i+1]==table[x_pos_b][y_pos_b]){
                                if(x_pos_a==x_pos_b || y_pos_a==y_pos_b){
                                    if(x_pos_a==x_pos_b){
                                        if(y_pos_a<4){
                                            cipher[i]=table[x_pos_a][y_pos_a+1];
                                        }else{
                                            cipher[i]=table[x_pos_a][0];
                                        }

                                        if(y_pos_b<4){
                                            cipher[i+1]=table[x_pos_b][y_pos_b+1];
                                        }else{
                                            cipher[i+1]=table[x_pos_b][0];
                                        }
                                    }
                                    if(y_pos_a==y_pos_b){
                                        if(x_pos_a<4){
                                            cipher[i]=table[x_pos_a+1][y_pos_a];
                                        }else{
                                            cipher[i]=table[0][y_pos_a];
                                        }
                                        if(x_pos_b<4){
                                            cipher[i+1]=table[x_pos_b+1][y_pos_b];
                                        }else{
                                            cipher[i+1]=table[0][y_pos_b];
                                        }
                                    }
                                }else{
                                    cipher[i]=table[x_pos_a][y_pos_b];
                                    cipher[i+1]=table[x_pos_b][y_pos_a];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cipher[leng+(leng)/2-1]='\0';

    diff = 0;

    for(int i=0;i < leng+(leng)/2-1;i++){
         if(i%3==2){
            for(int z=leng+(leng)/2-1;z > i; z--){
                cipher[z]=cipher[z-1];
            }
            cipher[i]=' ';
        }
    }

    free(mykey);
    free(mytext);

    return cipher;
}

char* playfair_decrypt(const char* key, const char* text){
if(key==NULL || text==NULL){
    return NULL;
}

int sof_key = strlen(key);

if(sof_key<1){
    return NULL;
}

char *mykey = (char*) malloc(sof_key*sizeof(char)+1);

for(int i=0; i<sof_key;i++){
  if(!isalpha(key[i])){
    free(mykey);
    return NULL;
  }
  mykey[i]=toupper(key[i]);
  if(mykey[i]=='W'){
      mykey[i]='V';
  }
}

char table[5][5] ;
char alpha[26];
strcpy(alpha, MAXSTR);

int count = -1;
  for(int i = 0 ; i<5; i++){
    for(int j = 0; j<5; j++){
      count++;
      if((count)<sof_key){
        table[i][j]=' ';
        for(int x=0; x < 25 ; x++){
          if(alpha[x]==mykey[count]){
              alpha[x]=' ';
              table[i][j]=mykey[count];
          }
        }
        if(table[i][j]==' '){
          if(j!=0){
            j--;
          }else{
            i--;
            j=4;
          }
        }
      }else{
        for(int x=0; x < 25 ; x++){
          if(alpha[x]!=' '){
            table[i][j]=alpha[x];
            alpha[x]=' ';
            break;
          }
        }
      }
    }
  }

    int leng = strlen(text);
    char mid[leng];
    strcpy(mid,text);

    for(int i=0;i < leng;i++){
        if(mid[i]==' '){
            for(int z=i ; z < leng ; z++){
                mid[z]=mid[z+1];
            }
         }
    }


    leng=leng-(leng+1)/3+1;

    char mytext[leng+1];
    mytext[(leng)]='\0';

    for(int i=0;i<leng+1;i++){
         mytext[i]=mid[i];
    }

    char *decrypt = (char*) malloc((leng)*sizeof(char)+1);
    for(int i=0;i <leng;i=i+2){
        for(int x_pos_a = 0 ; x_pos_a<5; x_pos_a++){
            for(int y_pos_a = 0; y_pos_a<5; y_pos_a++){
                if(mytext[i]==table[x_pos_a][y_pos_a]){
                    for(int x_pos_b = 0 ; x_pos_b<5; x_pos_b++){
                        for(int y_pos_b = 0; y_pos_b<5; y_pos_b++){
                            if (mytext[i+1]==table[x_pos_b][y_pos_b]){
                                if(x_pos_a==x_pos_b || y_pos_a==y_pos_b){
                                    if(x_pos_a==x_pos_b){
                                        if(y_pos_a>0){
                                            decrypt[i]=table[x_pos_a][y_pos_a-1];
                                        }else{
                                            decrypt[i]=table[x_pos_a][4];
                                        }
                                        if(y_pos_b>0){
                                            decrypt[i+1]=table[x_pos_b][y_pos_b-1];
                                        }else{
                                            decrypt[i+1]=table[x_pos_b][4];
                                        }
                                    }

                                if(y_pos_a==y_pos_b){
                                    if(x_pos_a>0){
                                        decrypt[i]=table[x_pos_a-1][y_pos_a];
                                    }else{
                                        decrypt[i]=table[4][y_pos_a];
                                    }
                                if(x_pos_b>0){
                                    decrypt[i+1]=table[x_pos_b-1][y_pos_b];
                                }else{
                                    decrypt[i+1]=table[4][y_pos_b];
                                }
                            }
                        }else{
                            decrypt[i]=table[x_pos_a][y_pos_b];
                            decrypt[i+1]=table[x_pos_b][y_pos_a];
                        }
                    }
                }
            }
         }
      }
    }
  }

  decrypt[leng]='\0';
  free(mykey);

  return decrypt;
}
