#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
#define M 800
int cmp(const void*a,const void*b)
{
	int *aa=(int*)a;
	int *bb=(int*)b;
	while(*aa!=-1&&*bb!=-1&&*aa==*bb)aa++;bb++;
	return *bb-*aa;
}
int main()
{
	int t;scanf("%d",&t);
	for(int i=0;i<t;i++){
		int n;
		int a[n][N];
		for(int j=0;j<n;j++){
			int k=0;
			while(scanf("%d",&a[j][k])&&a[j][k]!=-1)k++;
		}//输入数据
	qsort(a,n,sizeof(a[0]),cmp);
	for(int i=0;i<n;i++){
		int j;
		for(j=0;a[i][j+1]!=-1;j++){
			printf("%d ",a[i][j]);
		}
		printf("%d\n",a[i][j]);
	} 
	}
}