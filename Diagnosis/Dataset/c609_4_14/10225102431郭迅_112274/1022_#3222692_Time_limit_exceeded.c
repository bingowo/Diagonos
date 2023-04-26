#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1000000
int cmp(const void*a,const void*b)
{
	char *aa=(char*)a;
	char *bb=(char*)b;
	int i,j,t=0;
	for(i=0;*aa;i++){if((*aa+i)=='@')break;}
	for(j=0;*bb;j++){if((*bb+i)=='@')break;}
	int m=strcmp(aa+i+j,bb+j+1);
	if(m)return m;
	else return strcmp(aa,bb);
	
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