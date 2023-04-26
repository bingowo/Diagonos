#include <stdio.h>

#include <stdlib.h>

int main()
{
	for(int Y=0;Y<400;Y++)
	{
	int n,m,temp,TEMP;
	scanf("%d %d",&n,&m);
	int A[10][4]={0};
	int B[500][3];
	int C[10]={1,2,3,4,5,6,7,8,9,10};
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&B[i][0],&B[i][1],&B[i][2]);
	}
	for(int j=0;j<m;j++)
	{
		if(B[j][2]==1)
		{
			A[B[j][0]-1][0]++;
			A[B[j][1]-1][1]++;
			A[B[j][0]-1][3]+=3;
			A[B[j][1]-1][3]-=1;
		}
		else if(B[j][2]==-1)
		{
			A[B[j][0]-1][1]++;
			A[B[j][1]-1][0]++;
			A[B[j][0]-1][3]-=1;
			A[B[j][1]-1][3]+=3;
		}
		else if(B[j][2]==0)
		{
			A[B[j][0]-1][2]++;
			A[B[j][1]-1][2]++;
			A[B[j][0]-1][3]+=1;
			A[B[j][1]-1][3]+=1;
		}
	}
	for(int p=0;p<n-1;p++)
	{
		for(int q=p+1;q<n;q++)
		{
			if(A[p][3]<A[q][3])
			{
				temp=C[q];
				C[q]=C[p];
				C[p]=temp;
				TEMP=A[p][3];
				A[p][3]=A[q][3];
				A[q][3]=TEMP;
				TEMP=A[p][0];
				A[p][0]=A[q][0];
				A[q][0]=TEMP;
				TEMP=A[p][1];
				A[p][1]=A[q][1];
				A[q][1]=TEMP;
				TEMP=A[p][2];
				A[p][2]=A[q][2];
				A[q][2]=TEMP;
				
			}
			else if(A[p][3]==A[q][3])
			{
				if(A[p][0]<A[q][0])
				{
					temp=C[q];
					C[q]=C[p];
					C[p]=temp;
					TEMP=A[p][0];
					A[p][0]=A[q][0];
					A[q][0]=TEMP;
					TEMP=A[p][3];
					A[p][3]=A[q][3];
					A[q][3]=TEMP;
					TEMP=A[p][1];
					A[p][1]=A[q][1];
					A[q][1]=TEMP;
					TEMP=A[p][2];
					A[p][2]=A[q][2];
					A[q][2]=TEMP;
				}
				else if(A[p][0]==A[q][0])
				{
					if(A[p][1]>A[q][1])
					{
						temp=C[q];
						C[q]=C[p];
						C[p]=temp;
						TEMP=A[p][1];
						A[p][1]=A[q][1];
						A[q][1]=TEMP;
						TEMP=A[p][0];
						A[p][0]=A[q][0];
						A[q][0]=TEMP;
						TEMP=A[p][3];
						A[p][3]=A[q][3];
						A[q][3]=TEMP;
						TEMP=A[p][2];
						A[p][2]=A[q][2];
						A[q][2]=TEMP;
					}
					else if(A[p][1]==A[q][1])
					{
						if(C[p]>C[q])
						{
							temp=C[q];
							C[q]=C[p];
							C[p]=temp;
						}
					}
				}
			}
			else ;
		}
	}
	for(int T=0;T<n;T++)
	{
		printf("%d ",C[T]);
	}
	printf("\n");
	}
	return 0;
}