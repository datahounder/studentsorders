/*
CH-230-A
a6p7.c
Zarina Abulkassova
zabulkasso@jacobs-university.de
*/
int main()
{
	//declared char to use
	int i,shift,a,b,c;
    unsigned char ch;
	scanf("%c", &ch);
	scanf("%d%d%d",&a,&b,&c);

	//printed in decimal and binary
    printf("The decimal representation is: %d\n", ch);
	printf("The binary representation is: ");

	//for loop to shift by 7 fist then go on until 0 since
	//since we have 8 bits.
	for(i=7; i>=0; --i){
		shift = ch >> i;
		printf("%d", L(shift));
	}
	printf("\n");
	set3bits(&ch,a,b,c);
	printf("After setting the bits: ");
		for(i=7; i>=0; --i){
		shift = ch >> i;
		printf("%d", L(shift));
	}
	printf("\n");

	return 0;
}