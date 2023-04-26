#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
int afind(int*p,int x,int n)
{
	for(int i=0;i<n;i++) 
	{
		if(p[i]==x) return i;
	}
	return -1;
}
int cmp(const void*a,const void*b)
{
	int*p1=(int*)a;int*p2=(int*)b;
	return *p1-*p2;
}
int gc(int x,int y)
{
	//x<y 最小公倍数
	for(int i=2;i<=x;i++)
	{
		if(x%i==0&&y%i==0) return i;
	 } 
	return 1;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int temp=0;
		int n;
		scanf("%d",&n);
		int*p=(int*)malloc(n*sizeof(int));
		for(int j=0;j<n;j++)
		{
			int k=0;
			scanf("%d",&k);
			if(afind(p,k,temp)==-1) p[temp]=k,temp++;
		}
		qsort(p,temp,sizeof(p[0]),cmp);
		int count=0;
		for(int ii=0;ii<temp;ii++)
		{
			for(int j=ii+1;j<temp;j++)
				if(gc(p[ii],p[j])==1) count++;//printf("%d %d %d\n",gc(p[ii],p[j]),p[ii],p[j]);
		}
		printf("case #%d:\n%d\n",i,count);
	}
	
	return 0;
}