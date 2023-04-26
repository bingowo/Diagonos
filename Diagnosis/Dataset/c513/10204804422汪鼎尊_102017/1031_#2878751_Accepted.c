#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cmp(const void *a,const void *b)
{
	const int i1=*(int*)a,i2=*(int*)b;
	return i1-i2;
}

int main()
{
	int i,j=0,k;
	int len=0;
	int result=0,dim;
	int c,cases;
	int v1[10000],v2[10000];
	scanf("%d",&cases);
	for(c=0;c<cases;c++)
	{
		result=0;
		scanf("%d",&dim);
		for(i=0;i<dim;i++)scanf("%d",&v1[i]);
		for(i=0;i<dim;i++)scanf("%d",&v2[i]);
		qsort(v1,dim,sizeof(int),cmp);
		qsort(v2,dim,sizeof(int),cmp);
		for(i=0;i<dim;i++)result=result+v1[i]*v2[dim-i-1];
		printf("case #%d:\n",c);
		printf("%d",result);
		if(c!=cases-1)putchar('\n');
	}
	return 0;
}