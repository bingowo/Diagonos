#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double table[127];

int cmp1(const void *a,const void *b)
{
	return table[*(int *)a]-table[*(int *)b];
}


main()
{
	int T,i=0;
	scanf("%d",&T);
	while(T--)
	{
		for (int i='A';i<='Z';i++)
		{
			scanf("%lf",&table[i]);
			table[i+26]=table[i]+0.0001;		
		}
		char input[100];
		scanf("%s",input);
		qsort(input,strlen(input),sizeof(input[0]),cmp1);
		printf("case #%d:\n%s\n",i++,input);
	}
}
