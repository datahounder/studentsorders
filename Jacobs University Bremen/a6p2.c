/*
CH-230-A
a6p2.c
Zarina Abulkassova
zabulkasso@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>

//macro for least bit
#define Representative(A) A&1
int main()
{
    //declared char
    unsigned char A;
    printf("Enter your number:");
    scanf("%c",&A);
    //printed in decimal and least bit
    printf("The decimal representation is: %d\n",A);
    printf("The least significant bit is: %d\n", Representative(A));
    return 0;
}