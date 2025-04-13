#include <math.h>
#include <iostream>

int main()
{
const double ms=0;// Дифференциальное различие масштабов
const double Pi=3.14159265358979; // chislo PI
const double ro=206264.8062; // chislo uglovih secund v radiane
// ellipsoid Krasovskogo
const double aP=6378245;// bolshaya poluos
const double alP=1/298.3;// szhatie
//ellipsoid WGS 84 (GRS 80, eti 2 ellipsoida shdni po bolshinstvu parametrov)
const double aW=6378137; // bolshaya poluos
const double alW=1/298.257223563; // szhatie
//Линейные элементы трансформирования, в метрах
const double dx=23.92;
const double dy=-141.27;
const double dz=-80.9;
//Угловые элементы трансформирования, в секундах
const double wx=0;
const double wy=0;
const double wz=0;

double e2P; // kvadrat ekcentrensiteta
double e2W; // kvadrat ekcentrensiteta
double a,e2,da,de2; //Vspomogatelnie znacheniya dlya preobrazovaniya ellipsoidov
double B,L,M,N;
double WGS84Alt;
double dB,dL,dH;
double Ld,H,Bd;
double WGS84_CK42_Lat;
double CK42_WGS84_Lat;
double WGS84_CK42_Long;
double CK42_WGS84_Long;
{
printf("vvedite Bd:");
scanf("%f",&Bd);
printf("vvedite Ld:");
scanf("%f",&Ld);
printf("vvedite H:");
scanf("%f",&H);}
{
e2P=2*alP-(alP*alP); 
printf("e2P ravno = %f \n", e2P);
e2W=2*alW-(alW*alW);
a=(aP+aW)/2;
e2=(e2P+e2W)/2;
da=aW-aP;
de2=e2W-e2P;
B =Bd*Pi/180;
L =Ld*Pi/180;
M =pow(a*(1-e2)/(1-e2*sin(B)*sin(B)),1.5);
N =pow(a*(1-e2*sin(B)*sin(B)),-0.5);
dB =ro/(M+H)*(N/a*e2*sin(B)*cos(B)*da+(N*N/a*a+1)*N*sin(B)*cos(B)*de2/2-(dx*cos(L)+dy*sin(L))*sin(B)+dz*cos(B))-wx*sin(L)*(1+e2*cos(2*B))+wy*cos(L)*(1+e2*cos(2*B))-ro*ms*e2*sin(B)*cos(B);
dL=ro/((N+H)*cos(B))*(-dx*sin(L)+dy*cos(L))+tan(B)*(1-e2)*(wx*cos(L)+wy*sin(L))-wz;
dH=-a/N*da+N*sin(B)*sin(B)*de2/2+(dx*cos(L)+dy*sin(L))*cos(B)+dz*sin(B)-N*e2*sin(B)*cos(B)*(wx/ro*sin(L)-wy/ro*cos(L))+(a*a/N+H)*ms;
WGS84Alt=H+dH;
WGS84_CK42_Lat=Bd-(dB/3600);
CK42_WGS84_Lat=Bd+(dB/3600);
WGS84_CK42_Long=Ld-(dL/3600);
CK42_WGS84_Long=Ld+(dL/3600);
printf("izmenenie v shirote ravno = %f \n", dB,"gradusov"); 
printf("izmenenie v dolgote ravno = %f \n ", dL,"gradusov");
printf("izmenenie v visote ravno = %f \n ", dH,"metrov");
printf("WGS84Alt ravno = %f ", WGS84Alt);
printf("perevod iz WGS v CK42 po shirote = %f \n",WGS84_CK42_Lat,"gradusov"); 
printf("perevod iz CK42 v WGS84 po shirote = %f \n",CK42_WGS84_Lat,"gradusov"); 
printf("perevod iz WGS v CK42 po dolgote = %f \n",WGS84_CK42_Long,"gradusov"); 
printf("perevod iz CK42 v WGS84 po dolgote = %f \n",CK42_WGS84_Long,"gradusov"); 
return 0;}
}

 
