#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int MegaMethod(char * inStr);
void TurnNumToString(char * str, unsigned long int num);
/* TESTING MAIN
int main(){
	const int maxChars = 256;
	//Input is locked to maxChars
	char * input = malloc(maxChars*sizeof(char));
	input = "165";
	int output = MegaMethod(input);
	if(output == 3) printf("MegaMethod Test01 passed/n");
	input = "1721";
	output = MegaMethod(input);
	if(output == 2) printf("MegaMethod Test02 passed/n");
	free(input);
	return 0;
}
*/
int main(){
	const int maxChars = 100000;
	//Input is locked to maxChars
	char * input = malloc(maxChars*sizeof(char));
	scanf("%s",input);
	int output = MegaMethod(input);
	printf("%d\n", output);
	free(input);
	return 0;
}

int MegaMethod(char * inStr){
	unsigned long int sum = 0;
	for(int i = 0; i < strlen(inStr); ++i){
		char actC = inStr[i];
		sum += (actC - '0');
	}
	if(sum >= 10){
		const int maxChars = 100;
		char * input = malloc(maxChars*sizeof(char));
		TurnNumToString(input, sum);
		int output = MegaMethod(input);
		free(input);
		return output;
	}
	else
		return sum;
}

void TurnNumToString(char * str, unsigned long int num){
	const int maxChars = 10;
	unsigned long int tempNum = num;
	int strPos;
	for(strPos = 0; strPos < maxChars && tempNum != 0; ++strPos){
		char actC = '0' + (tempNum % 10);
		str[strPos] = actC;
		tempNum = tempNum / 10;
	}
	str[strPos] = '\0';	
}