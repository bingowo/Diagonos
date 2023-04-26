#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int T,j,res;
	scanf("%d",&T);
	int i;
	for(i=0;i<T;i++)
	{
		int x,y;
		j=0,res=0;
		scanf("%d %d",&x,&y);
		char a[33],b[33];
		for(j=0;j<33;j++)
		{
			a[j]='0';b[j]=0;
		}
		j=0;
		while(x>0)
		{
			a[j]=x%2+'0';
			x=x/2;
			j++;
		}
		j=0;
		while(y>0)
		{
			b[j]=y%2+'0';
			y=y/2;
			j++;
		}
		//printf("(%s %s)\n",a,b);
		for(j=0;j<strlen(a)&&j<strlen(b);j++)
		{
			if(a[j]!=b[j])res++;
		}
		printf("%d\n",res);
	}
	return 0;
}