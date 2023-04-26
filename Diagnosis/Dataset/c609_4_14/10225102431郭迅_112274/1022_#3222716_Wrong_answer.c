#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1000000
int cmp(const void*a,const void*b)
{
	char *aa=(char*)a;
	char *bb=(char*)b;
	int i,j;
	for(i=0;*aa;i++){if((*aa)!='@'){++aa;}else break;}
	for(j=0;*bb;j++){if((*bb)=='@'){++bb;}else break;}
	int m=strcmp(aa,bb);
	if(m)return m;
	else return strcmp((char*)a,(char*)b);
	
}
	
int main()
{
	int n;scanf("%d",&n);
	char s[n][N];
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);		
	}
	qsort(s,n,N,cmp);
	for(int i=0;i<n;i++){
		printf("%s\n",s[i]);
	}
}