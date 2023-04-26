#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void solve(int n,int m)
{
	int re[10000]={0};//存余数,数组序号为余数，对应值为余数对应的商的位数 
	int j=1;
	int t=n/m;
	re[n%m]=j++;
	n%=m;
	printf("%d.",t);
	while(n%m!=0)
	{  n*=10;
		t=n/m;
		n%=m;
		printf("%d",t);
		
		if(re[n])
		{
			putchar('\n');
			printf("%d-%d",re[n],j-1);
			return;
		}
		else re[n]=j++;
	 } 
	 	putchar('\n');
}


int main() 
{ int t,T;
	scanf("%d",&T);
	for(t=0;t<T;t++)
	{	int n,m;
		scanf("%d%d",&n,&m);
		printf("case #%d:\n",t);
		solve(n,m);
	}
    return 0;
}
