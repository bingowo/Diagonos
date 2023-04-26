#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int result,input;
	int i,t;
	
	int c,cases;
	scanf("%d",&cases);
	for(c=0;c<cases;c++)
	{
		result=0;t=0;
		scanf("%d",&input);
		for(i=0;i<31;i++)
		{
			if(1&((input>>i)^(input>>(i+1))))
			{
				t++;
				if(t>result)result=t;
			}
			else t=0;
		}
		
		
		
		
		printf("case #%d:\n%d",c,result);
		if(c!=cases-1)putchar('\n');
	}
	return 0;
}