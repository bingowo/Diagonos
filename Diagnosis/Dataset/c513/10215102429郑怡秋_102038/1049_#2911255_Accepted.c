#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int cmp(const void*a,const void*b)
{
	char*p1=*(char**)a;char*p2=*(char**)b;
	return strcmp(p1,p2);
}


int main()
{
	int t;
	scanf("%d\n",&t);
	for(int i=0;i<t;i++)
	{
		char A[501];
		gets(A);
		char B[501][501];
		int n=0,m=0,k=0;
		while(k<strlen(A))
		{
			m=0;
			while(A[k]!=' '&&A[k]!=','&&A[k]!='.'&&A[k]!='!'&&A[k]!='?'&&k<strlen(A))
			{
				B[n][m++]=A[k++];//printf("%c\n",B[n][m-1]);
			}B[n][m]='\0';
			k++;
			n++;
		}
		char* C[501];
		int num=0,tump;
		for(int j=0;j<n;j++)
		{
			tump=0;
			for(int l=j+1;l<n;l++)
			{
				if(strcmp(B[j],B[l])==0)  tump++;
			}
			if(tump==0) C[num++]=B[j];
		}
		qsort(C,num,sizeof(C[0]),cmp);
		printf("case #%d:\n",i);
		int j=0;
		for(;j<num-1;j++) if(strlen(C[j])>=1)printf("%s ",C[j]);
		printf("%s\n",C[num-1]);
		
	}
	return 0;
}