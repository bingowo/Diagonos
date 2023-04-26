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
void cor(char A[],int C[])
{   int la=strlen(A);int i,j;
	if(isdigit(A[la-1])&&la>=3&&A[la-2]!='^'&&A[la-3]!='^' || la<=2&&isdigit(A[la-1]))
		{int jo;
			for(jo=la-1;isdigit(A[jo]);jo--)
			{
				C[0]=C[0]+(A[jo]-'0')*po(la-jo-1);
			}
			if(A[jo]=='-') C[0]*=(-1);
			//printf("C[0]:%d\n",C[0]);
		}
		for(i=0;i<strlen(A);i++)
		{
			if(A[i]=='x') 
			{	//an1++;
				if(A[i+1]!='^'&&(i+1)<strlen(A))
				{
					int b=i-1;
					int q=0;
					while(b>=0&&isdigit(A[b])&&b<strlen(A)) C[1]=C[1]+(A[b--]-'0')*po(q++);
					if(C[1]==0&&(b<0||(b>=0&&(!isdigit(A[b]))))) C[1]=1; 
					if(b>=0&&A[b]=='-') C[1]*=(-1);//printf("C[1]:%d\n",C[1]);
				}
				else if(A[i+1]=='^'&&(i+1)<strlen(A))
				{
					int k=i+2;
					int n1=0;
					while(isdigit(A[k])&&k<strlen(A)) n1=n1*10+(A[k++]-'0');
					int q=0;
					int b=i-1;
					while(b>=0&&isdigit(A[b])&&b<strlen(A)) C[n1]=C[n1]+(A[b--]-'0')*po(q++);
					if(C[n1]==0&&(b<0||(b>=0&&(!isdigit(A[b]))))) C[n1]=1;
					if(b>=0&&A[b]=='-') C[n1]*=(-1);
					
					//printf("C :%d %d\n",C[n1],n1);				
				}
				
			}
		}
}

int main()
{
	char A[110],B[110];
	while(scanf("%s",A)!=EOF&&scanf("%s",B)!=EOF)
	{
		int C[52]={0},D[52]={0},E[100]={0};
		int n=0,m=0;
		int i,j;
		int an1=0,an2=0;
		//A
		cor(A,C);
		//if(an1==0) for(int i1=0;i1<strlen(A);i1++) C[0]=C[0]*10+(A[i1]-'0');
		//B
		cor(B,D);
		//if(an2==0) for(int i2=0;i2<strlen(A);i2++) D[0]=D[0]*10+(B[i2]-'0');
	//if(C[0]!=0) an1+=1;if(D[0]!=0) an2+=1;
	for(int j1=0;j1<50;j1++) for(int j2=0;j2<50;j2++) if(C[j1]!=0&&D[j2]!=0) E[j1+j2]+=C[j1]*D[j2];
	//if(an1>an2) an2=an1;
	int pp=99;
	//while(E[pp]==0) pp--;printf("p %d\n",pp);
	for(int q=pp;q>=0;q--) if(E[q]!=0) printf("%d ",E[q]);
	//printf("%d\n",E[0]);
	printf("\n");
	}
	return 0;
}