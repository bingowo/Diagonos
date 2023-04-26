#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int T,i=0,j,res,n,count;
	scanf("%d",&T);
	for(;i<T;i++)
	{
		res=0;
		count=0;
		j=0;
		scanf("%d",&n);
		char a[1000]={'\0'};
		while(n>0)
		{
			a[j]=n%2+'0';
			n=n/2;
			j++;
		}
		//printf("(%s)\n",a);
		if(strlen(a)==1)res=1;
		else{
			for(j=strlen(a)-1;j>0;j--)
				{
				if(a[j]!=a[j-1])
				{	count++;
					if(res<count){res=count;
					//printf("(%d)\n",res);
					}
				}
				else count=0;
			}
			res++;
		}
		printf("case #%d:\n",i);
		printf("%d\n",res);
	}
	return 0;
}