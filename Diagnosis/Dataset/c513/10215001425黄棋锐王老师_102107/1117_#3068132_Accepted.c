#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct
{
	long long x,y;
}point;

long long ABS(long long x)//绝对值 
{
	if(x<0) return -x;
	else return x;
}

long long max(long long x,long long y)
{
	if(x>y) return x;
	else return y;
}

int main() 
{ 	point P,D,T;
	scanf("%lld %lld",&P.x,&P.y);
	int n,i,j,k,l;
	scanf("%d",&n);
	scanf("%lld %lld",&D.x,&D.y);
	long long dis=max(ABS(D.x-P.x),ABS(D.y-P.y)),di=0;
	
	for(i=1;i<n;i++)
 {
	scanf("%lld %lld",&T.x,&T.y);
	di=max(ABS(T.x-P.x),ABS(T.y-P.y));
	if(di<dis) D=T,dis=di;
	else if(di==dis)
	{
		if(T.x<D.x) D=T;
		else if(T.x==D.x)
		{
			if(T.y<D.y) D=T;
		}
	}
 }
	
	printf("%lld\n",dis);
	printf("%lld %lld",D.x,D.y);
    return 0;
}