#include <stdio.h>
#include <stdlib.h>


int main()
{
	int T,i,res,j;
	scanf("%d",&T);
	char a[1000];
	for (i=0;i<T;i++)
	{
		res=0;
		scanf("%s",a);
		for(j=0;j<strlen(a);j++)
		{
			if(a[j]=='-')res=res*3-1;
			else res=res*3+a[j]-'0';
		 } 
		printf("case #%d:\n",i);
		printf("%d\n",res);
	}
	return 0;
	
	
}