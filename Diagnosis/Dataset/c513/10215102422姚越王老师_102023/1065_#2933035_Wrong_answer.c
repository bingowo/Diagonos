#include<stdio.h>
typedef struct{int a,b,totala,totalb;} STA;
int main()
{
	STA sta[21];
	int a,n,m,x,i,in2;
	scanf("%d %d %d %d",&a,&n,&m,&x);
	sta[0].a=1;sta[0].b=0;sta[1].totala=1;sta[1].totalb=0;
	sta[2].a=0;sta[2].b=0;sta[2].totala=1;sta[2].totalb=0;
	sta[3].a=1;sta[3].b=0;sta[3].totala=2;sta[3].totalb=0;
	sta[4].a=0;sta[4].b=1;sta[4].totala=2;sta[4].totalb=1;
	for(i=5;i<n;i++)
	{
		sta[i].a=sta[i-1].a+sta[i-1].a;
		sta[i].b=sta[i-1].b+sta[i-1].b;
		sta[i].totala=sta[i-1].totala+sta[i].a;
		sta[i].totalb=sta[i-1].totalb+sta[i].b;
	}
	in2=(m-sta[--i].totala*a)/sta[i].totalb;
	printf("%d",sta[x].totala*a+sta[x].totalb*in2);
}