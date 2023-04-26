#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct pos{
    long long int x;
    long long int y;
};
long long int step(unsigned long long d1,unsigned long long d2)
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
    struct pos L;
    scanf("%lld %lld",&L.x,&L.y);
    unsigned long long d1=llabs(L.x);
    unsigned long long d2=llabs(L.y);
    long long int res=step(d1,d2);
    printf("%lld",res);
    return 0;
}