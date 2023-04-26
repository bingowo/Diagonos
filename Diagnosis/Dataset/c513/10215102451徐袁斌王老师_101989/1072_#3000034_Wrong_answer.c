#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct pos{
    long long int x;
    long long int y;
};
int main()
{
    struct pos L;
    char s[100]={0};
    scanf("%lld %lld",&L.x,&L.y);
    int d=0,e=0;
    unsigned long long d1=llabs(L.x);
    unsigned long long d2=llabs(L.y);
	long long int num=0;
	long long int d3=0;
	if(d1==0 && d2==0) num=0;
	else if(d1%2 == d2%2) num=-1;
    else {while((d1+d2)!=1)
    {
    	if(d1%2==0)
    	{
    		if(d==0) d=1;
    		else d=0;
    		d3=d1;
    		d1=d2;
    		d2=d3;
		}
    	if(((llabs(d1)-1)/2)%2 != (llabs(d2)/2)%2 )
		{
			if(d==1) 
			{
				if(L.x>0&&L.y>0)s[e]='N';
				else s[e]='S';
				e++;
			}
			else 
			{
				if(L.x>0&&L.y>0)s[e]='E';
				else s[e]='W';
				e++;
			}
			d1=(d1-1)/2;
			d2=d2/2;
		}
		else
		{
			if(d==1) 
			{
				if(L.y>0)s[e]='S';
				else s[e]='N';
				e++;
			}
			else 
			{
				if(L.x>0)s[e]='W';
				else s[e]='E';
				e++;	
			}
			d1=(d1+1)/2;
			d2=d2/2;
		}
		num++;
	}
	if(d1%2==0)
	{
  		if(d==0) d=1;
  		else d=0;
	}
	if(d1==1&&d==0) s[e]='E';
	else if(d2==1&&d==0) s[e]='N';
	else if(d1==1&&d==1) s[e]='W';
	else s[e]='S';
    num=num+1;}
    printf("%lld\n",num);
    if(num!=-1)
    {
		for(int i=0;s[i]!=0;i++){printf("%c",s[i]);}
	}
    return 0;
}