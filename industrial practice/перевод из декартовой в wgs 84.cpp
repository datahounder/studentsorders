#include <math.h>
#include <stdio.h>
int main()
{
const double Pi=3.1415; // chislo PI
const double a=6378245;// bolshaya poluos
const double alP=1/298.3;// szhatie

double X, Y, Z, e, r;
double D, H, L, B, La, Ld, Bd;
double c, s1, s2, b, p, d, qq;
printf("vvedite X:");
scanf("%lf",&X);
printf("vvedite Y:");
scanf("%lf",&Y);
printf("vvedite Z:");
scanf("%lf",&Z);
D=sqrt(X*X+Y*Y);
printf("D = %lf \n",D,"metrov");
e=2*alP-(alP*alP);
qq=asin(Y/D);
La=fabs(qq);
printf("qq = %lf \n",qq,"radian");
printf("La = %lf \n",La,"radian");
{
if(D==0) 
{
B=Pi*Z/(2*fabs(Z)); 
L=0; 
 H=Z*sin(B)-a*sqrt(1-e*e*sin(B)*sin(B));
}
else
{
if((Y<0)&&(X>0)) L=2*Pi-La;
else if((Y<0)&&(X<0)) L=Pi+La;
else if((Y>0)&&(X<0)) L=Pi-La;
else if((Y>0)&&(X>0)) L=La;
else if((Y=0)&&(X>0)) L=0;
else if((Y=0)&&(X<0)) L=Pi;
}
}
{
if(Z==0)
{B=0;
H=D-a;
}
else
{
r=sqrt(X*X+Y*Y+Z*Z);
c=asin(Z/r);
p=e*e*a/(2*r);
s1=0;
b=c+s1;
s2=asin(p*sin(2*b)/sqrt(1-e*e*sin(B)*sin(B)));
d=fabs(s2-s1);
B=b;
H=D*cos(B)+Z*sin(B)-a*sqrt(1-e*e*sin(B)*sin(B));
}
}
Ld=L*180/Pi;
Bd=B*180/Pi;
printf("perevod iz dekartovoi v CK42 po shirote = %lf \n",Bd,"gradusov"); 
printf("perevod iz dekartovoi v CK42 po dolgote = %lf \n",Ld,"gradusov"); 
printf("perevod iz dekartovoi v CK42 po visote = %lf \n",H,"metrov");
}
