#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int result,i1,i2;
	int i,t;
	
	int c,cases;
	scanf("%d",&cases);
	for(c=0;c<cases;c++)
	{
		result=0;
		scanf("%d%d",&i1,&i2);
		for(i=0;i<=31;i++)if(((i1>>i)^(i2>>i))&1)result++;
		
		//printf("case #%d:\n%d",c,result);
		printf("%d",result);
		if(c!=cases-1)putchar('\n');
	}
	return 0;
}