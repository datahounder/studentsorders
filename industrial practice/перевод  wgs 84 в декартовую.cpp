#include <math.h>
#include <stdio.h>
//using namespace std;
int main()
{
const double ms=0;// Дифференциальное различие масштабов
const double Pi=3.1415; // chislo PI
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
double WGS84ALT;
double dB,dL,dH;
double Ld,H,Bd;
double WGS84_CK42_Lat;
double CK42_WGS84_Lat;
double WGS84_CK42_Long;
double CK42_WGS84_Long;
double X,Y,Z,e,N1;
//cout<<"vvedite shirotu:";
//cin>>Bd;
//cout<<"vvedite dolgotu:";
//cin>>Ld;
//cout<<"vvedite visotu:";
//cin>>H;
printf("vvedite Bd:");
scanf("%lf",&Bd);
printf("vvedite Ld:");
scanf("%lf",&Ld);
printf("vvedite H:");
scanf("%lf",&H);
e2P=2*alP-(alP*alP); 
e2W=2*alW-(alW*alW);
a=(aP+aW)/2;
e2=(e2P+e2W)/2;
da=aW-aP;
e=2*alW-(alW*alW);
de2=e2W-e2P;
B=Bd*Pi/180;
L=Ld*Pi/180;
printf("L = %lf \n",L,"gradusov"); 
M=pow(a*(1-e2)/(1-e2*sin(B)*sin(B)),1.5);
N=pow(a*(1-e2*sin(B)*sin(B)),-0.5);
dB=ro/(M+H)*(N/a*e2*sin(B)*cos(B)*da+(N*N/a*a+1)*N*sin(B)*cos(B)*de2/2-(dx*cos(L)+dy*sin(L))*sin(B)+dz*cos(B))-wx*sin(L)*(1+e2*cos(2*B))+wy*cos(L)*(1+e2*cos(2*B))-ro*ms*e2*sin(B)*cos(B);
dL=ro/((N+H)*(cos(B))*(-dx*sin(L)+dy*cos(L))+tan(B)*(1-e2)*(wx*cos(L)+wy*sin(L))-wz);
dH=-a/(N*da+N*sin(B)*sin(B)*de2/2+(dx*cos(L)+dy*sin(L))*cos(B)+dz*sin(B)-N*e2*sin(B)*cos(B)*(wx/ro*sin(L)-wy/ro*cos(L))+(a*a/N+H)*ms);
WGS84ALT=H-(dH/3600);
WGS84_CK42_Lat=Bd-(dB/3600);
CK42_WGS84_Lat=Bd+(dB/3600);
WGS84_CK42_Long=Ld-(dL/3600);
CK42_WGS84_Long=Ld+(dL/3600);
N1=aP/sqrt(1-e*e*sin(B)*sin(B));
X=(N1+H)*cos(B)*cos(L);
Y=(N1+H)*cos(B)*sin(L);
Z=((1-e*e)*N1+H)*sin(B);
printf("izmenenie v shirote ravno = %lf \n",dB,"gradusov"); 
printf("izmenenie v dolgote ravno = %lf \n ",dL,"gradusov");
printf("izmenenie v visote ravno = %lf \n ",dH,"metrov");
printf("WGS84Alt ravno = %lf \n", WGS84ALT);
printf("perevod iz WGS84 v dekartovuu. X = %lf \n",X,"metrov"); 
printf("perevod iz WGS84 v dekartovuu. Y = %lf \n",Y,"metrov"); 
printf("perevod iz WGS84 v dekartovuu. Z = %lf \n",Z,"metrov"); 
return 0;
}

 
