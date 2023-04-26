#include <stdio.h>
#include<stdlib.h> 
#include<string.h>


int main()
{ 
	int T,i,j,k,cout1=0,cout0=0;
	char s; 
	int a,b,c;
	unsigned int t=0;
	scanf("%d",&T);
	s=getchar();
	for(i=0;i<T;i++)
	{ 
		cout1=0;cout0=0;
		while((s=getchar())!='\n')
		{
			t=(unsigned int)s;
			for(k=0;k<8;k++)
			{
				if(t&1==1)
				{
					cout1++;
				}
				else 
				{
					cout0++;
				}
					t=((unsigned int)t>>1);
			}
	
		}
		a=cout1;b=cout1+cout0;
		c=b%a;
		while(c)
		{
			b=a;
			a=c;
			c=b%a; 
		}
		printf("%d/%d\n",cout1/a,(cout1+cout0)/a);
	}
} 
