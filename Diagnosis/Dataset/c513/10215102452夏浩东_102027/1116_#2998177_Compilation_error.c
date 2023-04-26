#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long int step(long long d1,long long d2)
{
	long long int num=0;
	long long int d3=0;
	if(d1==0 && d2==0) return 0;
	if(d1%2 == d2%2) return -1;
    while((d1+d2)!=1)
    {
    	if(d1%2==0)
    	{
    		d3=d1;
    		d1=d2;
    		d2=d3;
		}
    	if(((d1-1)/2)%2 != (d2/2)%2 )
		{
			d1=(d1-1)/2;
			d2=d2/2;
		}
		else
		{
			d1=(d1+1)/2;
			d2=d2/2;
		}
		num++;
	}
    return num+1;	
}
int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    qsort(L,cnt,sizeof(L[0]),cmp);
    long long dit =(long long)(llabs)x+(long long)(llabs)y;
    long long int res=0;
    long long d1=llabs(x);
    long long d2=llabs(y);
    long long int re=step(d1,d2);
    printf("%lld",re);
    return 0;
}