#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char c[20]={'\0'};
int cmp(const void*a,const void*b)
{
	return *(char*)a-*(char*)b;
}
void print(char*a,int len,int l,int des)//DFS深度优先算法
{
	if(l==des) return;
	for(;l<des;l++)
	{c[len]=a[l];
	c[len+1]='\0';
	printf("%s\n",c);
	print(a,len+1,l+1,des);
	}
}
int main()
{  int k,T;
	scanf("%d\n",&T);
	for(k=0;k<T;k++)
	{  	char s[20]={'\0'};
		char a[20]={'\0'};
		int  f[200]={0};
		int i=0,j=0,d=0,l=0;
		char c;
		while((c=getchar())!='\n')
		{   
			if(f[c]==0) a[l++]=c;
			f[c]=1;
		}
	 		printf("case #%d:\n",k);
	 	qsort(a,l,sizeof(char),cmp);
	 	print(a,0,0,l);
	}
	return 0;
}