
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//main function
int main()
{
    //declared stack,count and n
    Stack s;
    s.count = 0;
    unsigned int n;
    scanf("%d",&n);
    //called function binary function from other file
    binary(&s,n);
    //printed in binary representation
    printf("The binary representation of %u is: ",n);
    while(s.count>0){
        printf("%d",pop(&s));
    }
    printf(".\n");
    return 0;
}
