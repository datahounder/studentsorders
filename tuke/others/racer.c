#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int n = 0,t = 0;
	if(!scanf("%d %d",&n,&t)) return 0;
	if((n < 0) || (n > 1000) || (t < 0) ||(t > pow(10,6))) return 0;
	int celkova_draha = 0, celkova_rychlost = 0;
	for(int i = 0;i < n;i++){
		int s = 0,v = 0;
		if(!scanf("%d %d",&s,&v)) return 0;
		if((s < 0)||(s > 1000)||(v < -1000)||(v > 1000)) return 0;		
		celkova_draha += s;
		celkova_rychlost += v;
	}
	double celkovo_priemerna_rychlost = (double)celkova_draha / (float)t;
	double celkovo_zdanliva_rychlost = (double)celkova_rychlost / (float)n;
	printf("%.9lf",celkovo_priemerna_rychlost - celkovo_zdanliva_rychlost);
	return 0;
}