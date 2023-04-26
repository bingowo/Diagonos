#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>

int add(int a[],int b[],int c[],int max)
{
	int pop[25]={97,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
	int ca=0,i=0;
	for(int k=max-1;k>=0;k--,i++)
	{
		int n=a[k]+b[k]+ca;printf("%d\n",n);
		if(n>=pop[24-i]) 
		{
			ca=1;
			c[i]=n-pop[24-i];
		}
		else if(n<pop[24-i]) 
		{
			ca=0;c[i]=n;
		}
	}
	if(ca>0) {c[i]=ca;return i;}
	else return i-1;
}



int main()
{
	int T;
	scanf("%d",&T);
	int i;
	for(i=0;i<T;i++)
	{
		int A[40]={0},B[40]={0},E[40]={0};
		char C[100],D[100];
		scanf("%s%s",C,D);
		int c=strlen(C),d=strlen(D);int cc=0,dd=0;
		for(int j=0;j<c;j++) if(C[j]==',') cc++;
		for(int j=0;j<d;j++) if(D[j]==',') dd++;
		int max=cc+1;
		if(cc<dd) max=dd+1;
		int a=max-1,b=max-1;
		int y=0;int j1=c-1;
		while(j1>=0)
		{
			while(C[j1]!=','&&j1>=0)
			{
				if(C[j1-1]!=',') {A[a]=(C[j1]-'0')+(C[j1-1]-'0')*10;j1-=2;}
				else A[a]=C[j1]-'0',j1--;
				a--;
			}
			j1--;
		}
		int j2=d-1;
		while(j2>=0)
		{
			while(D[j2]!=','&&j2>=0)
			{
				if(D[j2-1]!=',') {B[b]=(D[j2]-'0')+(D[j2-1]-'0')*10;j2-=2;}
				else B[b]=D[j2]-'0',j2--;
				b--;
			}
			j2--;
		}
		//for(int j=0;j<max;j++) printf("%d\n",A[j]);
		int ii=0;
		ii=add(A,B,E,max);
		printf("case #%d:\n",i);
		for(int j=ii;j>0;j--) printf("%d,",E[j]);
		printf("%d\n",E[0]);
	}
	return 0;
}