#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
	int*s1,*s2;
	s1=(int*)a;
	s2=(int*)b;
	while(*s1!=-1&&*s2!=-1&&*s1==*s2)
	{
		s1++;
		s2++;
	}
	return *s2-*s1;
 }
int main()
{
	int T,N;
	int i,j,k;
	int d[1000][51];
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d",&N);
		for(k=0;k<N;k++)
		{
			j=0;
			while(scanf("%d",&d[k][j])&&d[k][j]!=-1)
			{
				j++;
			}
		}
		qsort(d,N,sizeof(d[0]),cmp);
		for(k=0;k<N;k++)
		{
			for(j=0;d[k][j+1]!=-1;j++)
			{
				printf("%d ",d[k][j]);
			}
			printf("%d\n",d[k][j]);
		}
	}
}