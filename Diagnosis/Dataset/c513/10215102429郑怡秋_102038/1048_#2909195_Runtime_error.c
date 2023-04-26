#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int po(int x)
{
	int ans=1;
	for(int i=0;i<x;i++)
	{
		ans*=10;
	}
	return ans;
}
int main()
{
	char A[110],B[110];
	while(scanf("%s",A)!=EOF&&scanf("%s",B)!=EOF)
	{
		int C[52]={0},D[52]={0},E[52]={0};
		int n=0,m=0;
		int i,j;
		int an1=0,an2=0;
		//A
		for(i=0;i<strlen(A);i++)
		{
			if(A[i]=='x') 
			{	an1++;
				if(A[i+1]!='^'&&(i+1)<strlen(A))
				{
					int b=i-1;
					int q=0;
					while(isdigit(A[b])&&b>=0&&b<strlen(A)) C[1]=C[1]+(A[b--]-'0')*po(q++);
					if(i-1-q>=0&&A[i-1-q]=='-') C[1]*=(-1);
					int k=i+2;
					while(isdigit(A[k])&&k<strlen(A)) C[0]=C[0]*10+(A[k++]-'0');
					if(A[i+1]=='-') C[0]*=(-1);
				}
				else if(A[i+1]=='^'&&(i+1)<strlen(A))
				{
					int k=i+2;
					int n1=0;
					while(isdigit(A[k])&&k<strlen(A)) n1=n1*10+(A[k++]-'0');
					int q=0;
					int b=i-1;
					while(isdigit(A[b])&&b>=0&&b<strlen(A)) C[n1]=C[n1]+(A[b--]-'0')*po(q++);
					if(i-1-q>=0&&A[i-1-q]=='-') C[n1]*=(-1);				
				}
				
			}
		}
		if(an1==0) for(int i1=0;i1<strlen(A);i1++) C[0]=C[0]*10+(A[i1]-'0');
		//B
		for(i=0;i<strlen(B);i++)
		{
			if(B[i]=='x') 
			{	an2++;
				if(B[i+1]!='^'&&(i+1)<strlen(B))
				{
					int b=i-1;
					int q=0;
					while(isdigit(B[b])&&b>=0&&b<strlen(B)) D[1]=D[1]+(B[b--]-'0')*po(q++);
					if(i-1-q>=0&&B[i-1-q]=='-') D[1]*=(-1);
					int k=i+2;
					while(isdigit(B[k])&&k<strlen(B)) D[0]=D[0]*10+(B[k++]-'0');
					if(B[i+1]=='-') D[0]*=(-1);
				}
				else if(B[i+1]=='^'&&(i+1)<strlen(B))
				{
					int k=i+2;
					int n1=0;
					while(isdigit(B[k])&&k<strlen(B)) n1=n1*10+(B[k++]-'0');
					int q=0;
					int b=i-1;
					while(isdigit(B[b])&&b>=0&&b<strlen(B)) D[n1]=D[n1]+(B[b--]-'0')*po(q++);
					if(i-1-q>=0&&B[i-1-q]=='-') D[n1]*=(-1);				
				}
				
			}
		}
		if(an2==0) for(int i2=0;i2<strlen(A);i2++) D[0]=D[0]*10+(B[i2]-'0');
	for(int j1=0;j1<an1;j1++) for(int j2=0;j2<an2;j2++) E[j1+j2]=C[j1]*D[j2];
	if(an1>an2) an2=an1;
	for(int q=an2-1;q>0;q++) printf("%d ",E[q]);
	printf("%d\n",E[0]);
	}
	return 0;
}