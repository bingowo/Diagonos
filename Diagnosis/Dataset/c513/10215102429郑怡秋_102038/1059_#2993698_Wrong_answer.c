#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
#define N 1111
#define INF 1000009
int gc(int x,int y)
{
	int n=0;
	for(int i=1;i<=x;i++) if(x%i==0&&y%i==0) return i;
}
int cmp(const void*a,const void*b)
{
	return (*(int*)a-*(int*)b);
}
int main()
{
	int n,s;
	scanf("%d%d",&n,&s);
	int*p=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++) scanf("%d",&p[i]);
	qsort(p,n,sizeof(int),cmp);
	p[n]=INF;
	int ans_int,ans_fz,ans_fm;
	
	
	for(int j=1;j<=n;j++)
	{
		int c=(p[j]-p[j-1])*j;
		if(s<c)
		{
			ans_int=p[j-1]+s/j;
			ans_fz=s%j;
			ans_fm=j;
			break;
		}
		else s-=c;
	}
	int g=gc(ans_fm,ans_fz);
	
	if(ans_fm<ans_fz) g=gc(ans_fz,ans_fm);
	ans_fz/=g;
	ans_fm/=g;
	if(ans_int==0&&ans_fz>0) printf("%d/%d",ans_fz,ans_fm);
	else
	{
		printf("%d",ans_int);
		if(ans_fz>0) printf("+%d/%d",ans_fz,ans_fm);
	}
	printf("\n");
	
	free(p);
	return 0;
}