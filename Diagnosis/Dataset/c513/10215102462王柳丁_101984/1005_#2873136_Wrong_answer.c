#include <stdio.h>
#include <stdlib.h>


int main()
{
	int t,i,j,n;
	long double e,res,res1;
	scanf("%d",&t);
	char a[1000];
	for(i=0;i<t;i++)
	{
		res=0,n=0;
		e=1.0/8;
		scanf("%s",a);
		j=2;
		while(a[j]!='\0')
		{
			res=res+(a[j]-'0')*e;
			j++;
			e=e/8;
		}
		res1=res;
		while(res1>0){
			res1=res1/0.1;
			n++;
		}
		printf("case #%d:\n",i);
		printf("%.nLf\n",res);
		
	}
	
	return 0;
	
	
}