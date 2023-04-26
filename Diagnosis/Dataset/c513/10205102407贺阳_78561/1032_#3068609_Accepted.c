#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b);
int main(){
	int T,N;
	scanf("%d\n",&T);
	int i=0;
	for(;i<T;i++)
	{
		scanf("%d\n",&N);
		int line_data[1000][51];
		int k=0;
		for(;k<N;k++)
		{
			int j=0;
			while(scanf("%d",&line_data[k][j])&&
			line_data[k][j]!=-1) j++;
		}
		qsort(line_data,N,sizeof(line_data[0]),cmp);
		k=0;
		for(; k<N; k++)
		{
			int j=0;
			for(j; line_data[k][j+1]!=-1; j++)
				printf("%d ",line_data[k][j]);
			printf("%d\n",line_data[k][j]);
		}
	}
	
	return 0;
}
int cmp(const void *a,const void *b)
{
	int *s1,*s2;
	s1=(int*)a;
	s2=(int*)b;
	while(*s1!=-1&&*s2!=-1&&s1==s2) s1++,s2++;
	return *s2-*s1;
	
}
