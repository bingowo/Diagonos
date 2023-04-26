#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>

void ch(int j,int k,int A[],int B[],int C[],char D[])
{
	int i;char sr;
	int *p1=A,*p2=B,*p3=C;
	char *p4=D;
	sr=*(p4+j);*(p4+j)=*(p4+k);*(p4+k)=sr;
	i=*(p1+j);*(p1+j)=*(p1+k);*(p1+k)=i;
	i=*(p2+j);*(p2+j)=*(p2+k);*(p2+k)=i;
	i=*(p3+j);*(p3+j)=*(p3+k);*(p3+k)=i;
}



int main()
{

	int n,m;
	while(1)
	{
		scanf("%d%d",&n,&m);
		if(n==0&&m==0) break;
		int A[10]={0};
		int B[10]={0};
		int C[10]={0};
		char D[10]={'1','2','3','4','5','6','7','8','9',':'};
		int i;
		for(i=0;i<m;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if(c==1) {A[a-1]+=3;B[a-1]+=1;A[b-1]-=1;C[b-1]+=1;}
			else if(c==-1) {A[a-1]-=1;C[a-1]+=1;A[b-1]+=3;B[b-1]+=1;}
			else if(c==0) {A[a-1]+=1;A[b-1]+=1;}
			//printf("A: %d %d %d \n",A[0],A[1],A[2]);
		//printf("B: %d %d %d \n",B[0],B[1],B[2]);
		//	printf("C: %d %d %d \n",C[0],C[1],C[2]);
		}
		int j=0,k=0;
		for(j=0;j<n;j++)
		{
			for(k=j+1;k<n;k++)
			{
				if(A[j]<A[k]) ch(j,k,A,B,C,D);
				else if(A[j]==A[k])
				{
					if(B[j]<B[k]) ch(j,k,A,B,C,D);
					else if(B[j]==B[k])
					{
						if(C[j]>C[k]) ch(j,k,A,B,C,D);
						else if(C[j]==C[k]) 
						{
							if(D[j]>D[k]) ch(j,k,A,B,C,D);
						}
					}
				}
			}
		}
		for(int q=0;q<n-1;q++) printf("%d ",D[q]-'0');
		printf("%d\n",D[n-1]-'0');
	}
	return 0;
}