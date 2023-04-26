#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int T;
	scanf("%d",&T);
	int i;
	for(i=0;i<T;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int t;
		if(x<y) {t=x;x=y;y=t;}
		int a,b,n=0;
		while(x)
		{
			a=x&1;b=y&1;
			if(a!=b) n++;
			x>>=1;y>>=1;
		}
		printf("%d\n",n);
	}
	return 0;
}