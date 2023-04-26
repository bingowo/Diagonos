#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#define M 50
void mul(int b[],int k)
{
	for(int j=M-1;j>0;j--) b[j]*=k;
	for(int j=M-1;j>0;j--)
	{
		b[j-1]+=b[j]/10;
		b[j]%=10;
		//if(b[j]!=0) printf("b:%d ",b[j]);
	}
}

void add(int D[],int B[])
{
	for(int j=M-1;j>0;j--)
	{
		D[j]+=B[j];
		D[j-1]+=D[j]/10;
		D[j]%=10;
	}
}

int main()
{
	int A[]={1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	int B[27][M+1]={0};
	int D[M+1]={0};
	int i=0;
	do{
	scanf("%d",&B[i++][M-1]);
	int f=B[i-1][M-1];
	if(f>10) B[i-1][M-1]=f%10,B[i-1][M-2]=f/10;
	}while(getchar()==',');
	//int j=0;
	for(int k=i-1;k>=0;k--)
	{
		for(int j=k;j>=0;j--)
		{
			//printf("\nA:%d\n",A[i-k-1]);
			mul(B[j],A[i-k-1]);
			//for(int o=0;o<M;o++) printf("%d ",B[o]);
		}
		add(D,B[k]);
	}
	int j=0;
	while(j<M)
	{
		if(D[j]==0) j++;
		else break;
	}
	for(int l=j;l<M;l++)
	{
		printf("%d",D[l]);
	}
	if(j==M) printf("0");
	printf("\n");
	
	
	
	return 0;
}