#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	char j;
	int a,l[1001]={0},i;
	scanf("%c",&j);
	while(scanf("%d",&a)!=EOF)
	{
		l[a]=1;
	}
	if (j=='A')
	{
		for(i=0;i<1001;i++)
		{
			if (l[i]==1) printf("%d ",i);
		}
	}
	else
	{
		for(i=999;i>=0;i--)
		{
			if (l[i]==1) printf("%d ",i);
		}
	}
	return 0;
}