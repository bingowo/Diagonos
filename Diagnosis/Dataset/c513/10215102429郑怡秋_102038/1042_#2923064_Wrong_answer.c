#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int cmp(const void*a,const void*b)
{
	char*p1=(char*)a;char*p2=(char*)b;
	return strcmp(p1,p2);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		char s[20];
		scanf("%s",s);
		char A[20];int m=0,in=0;
		for(int j=0;j<strlen(s);j++)
		{//printf("%d\n",j);
			m=0;
			for(int k=j+1;k<strlen(s);k++)
			{
				if(s[j]==s[k]) 
				{
					m=1;break;
				}
			}
			if(m==0) A[in++]=s[j];
		}
		long long an=(1<<in)-1;
		char B[100000][20];
		int m1=0,m2=0;
		for(long long j=1;j<=an;j++)
		{
			int h=0;
			m2=0;
			while(j>>h)
			{
				if((j>>h)&1==1) B[m1][m2++]=A[in-1-h];
				h++;
			}
			B[m1][m2]='\0';m1++;
			//printf("%s\n",B[m1-1]);
		}
		qsort(B,m1,sizeof(B[0]),cmp);
		printf("case #%d:\n",i);
		for(int j=0;j<m1;j++) printf("%s\n",B[j]);
	}
	return 0;
}