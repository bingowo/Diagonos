#include <stdio.h>
#include <stdlib.h>


int main()
{
	int t,i,j;
	double e,res;
	scanf("%d",&t);
	char a[1000];
	for(i=0;i<t;i++)
	{
		res=0;
		e=1.0/8;
		scanf("%s",a);
		printf("%.3f",e);
		j=2;
		while(a[j]!='\0')
		{
			res=res+(a[j]-'0')*e;
			j++;
			e=e/8;
		}
		printf("case #%d:\n",i);
		printf("%f\n",res);
		
	}
	
	return 0;
	
	
}