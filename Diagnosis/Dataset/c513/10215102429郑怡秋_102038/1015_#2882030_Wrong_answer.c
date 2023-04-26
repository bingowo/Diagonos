#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>

int add(int a[],int b[],int c[],int max)
{
	int pop[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
	int ca=0,i=0;
	for(int k=max-1;k>=0;k--,i++)
	{
		int n=a[k]+b[k]+ca;
		if(n>=pop[25-i]) 
		{
			ca=n/pop[25-i];
			c[i]=n-pop[25-i];
		}
		else if(n<pop[25-i]) 
		{
			ca=0;c[i]=n;
		}
	}
	if(ca>0) {
		c[i]=ca;return i;
	}
	else return i-1;
}



int main()
{
	int T;
	scanf("%d",&T);
	int i;
	for(i=0;i<T;i++)
	{
		int A[30]={0},B[30]={0},E[30]={0};
		char C[60],D[60];
		scanf("%s%s",C,D);
		int c=strlen(C),d=strlen(D);int max=(c+1)/2;
		if(c<d) max=(d+1)/2;
		int a=max-1,b=max-1;
		for(int j=c-1;j>=0;j--) if(C[j]!=',') A[a--]=C[j]-'0';
		for(int j=d-1;j>=0;j--) if(D[j]!=',') B[b--]=D[j]-'0';
		//for(int j=0;j<max;j++) printf("%d\n",A[j]);
		int ii=0;
		ii=add(A,B,E,max);
		printf("case #%d:\n",i);
		for(int j=ii;j>0;j--) printf("%d,",E[j]);
		printf("%d\n",E[0]);
	}
	return 0;
}