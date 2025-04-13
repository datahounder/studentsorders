#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"
#include "playfair.h"

int main () {
char *encrypted, *decrypted;
// even length of string
encrypted = playfair_encrypt("SeCReT", "Hello world");
printf("%s \n", encrypted);
// "Hello world" --> "HELXLOVORLDX"
// IS JZ JQ XN TK JC
decrypted = playfair_decrypt("SeCReT", encrypted);
printf("%s \n" , decrypted);
// HELXLOVORLDX
free(encrypted);
free(decrypted);


char* encrypted2;
// basic test with long text
encrypted2 = bmp_encrypt("CoMPuTeR", "Hello world!");
printf("%s\n", encrypted2);
char* decrypted2;
// basic test with long text
decrypted2 = bmp_decrypt("CoMPuTeR", encrypted2);
printf("%s\n", decrypted2);


// "JSXAI PSINR!"
/*bmp_encrypt(key,text);
bmp_decrypt(key,text);
playfair_encrypt(key,text);
playfair_decrypt(key,text);
printf("ahoj");*/
return 0;
}
