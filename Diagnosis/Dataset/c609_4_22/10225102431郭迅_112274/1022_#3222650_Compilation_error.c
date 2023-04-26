#include<stdio.h>
#include<stdlib.h>
#define N 1000000
int cmp(const void*a,const void*b)
{
	char *aa=(char*)a;
	char *bb=(char*)b;
	int i,j,t=0;
	for(i=0;*aa;i++){if((*aa)=='@')break;}
	for(j=0;*bb;j++){if((*bb)=='@')break;}
	int m=strcmp(aa+i+j,bb+j+1);
	if(m)return m;
	else return strcmp(a,b);
	
}//长度不同
	
int main()
{
	int n;scanf("%d",&n);
	char s[n][N];
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);		
	}
	qsort(s,n,N,strcmp);
	for(int i=0;i<n;i++){
		printf("%s\n",s[i]);
	}
}