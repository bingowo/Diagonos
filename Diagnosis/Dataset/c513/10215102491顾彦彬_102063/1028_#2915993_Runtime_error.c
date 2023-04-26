#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int cmp1(const void *a,const void *b)
{
	int x=*(int*)a;
	int y=*(int*)b;
	return x-y;
}
main()
{
	char T;
	int input,table[101],i=0;
	scanf("%s",&T);
	for (i;scanf("%d",&input);i++)
		table[i]=input;
	qsort(table,i-1,sizeof(table[0]),cmp1);
	for (int j=0;j<i-1;j++)
	{
		if (table[j]==table[j+1])
		{
			for (int k=j;k<i-1;k++)
				table[k]=table[k+1];
			i=i-1;	
		}
	}
	for (int j=0;j<i;j++)
		printf("%d ",table[j]);
} 