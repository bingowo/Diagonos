#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>

int main()
{
	int T;
	scanf("%d",&T);
	for(int j=0;j<T;j++)
	{
		char A[25];
		scanf("%s",A);
		int z=0,o=0,w=0,u=0,h=0,g=0,f=0,x=0,s=0,i=0; 
		for(int k=0;k<strlen(A);k++)
		{
			if(A[k]=='Z') z++;
			else if(A[k]=='O') o++;
			else if(A[k]=='W') w++;
			else if(A[k]=='U') u++;
			else if(A[k]=='H') h++;
			else if(A[k]=='G') g++;
			else if(A[k]=='F') f++;
			else if(A[k]=='X') x++;
			else if(A[k]=='S') s++;
			else if(A[k]=='I') i++;
		}
		int B[12];
		B[0]=z;
		B[1]=o-z-w-u;
		B[2]=w;
		B[3]=h-g;
		B[4]=u;
		B[5]=f-u;
		B[6]=x;
		B[7]=s-x;
		B[8]=g;
		B[9]=i-x-f+u-g;
		int l=o+h+s+i-x;
		printf("case #%d:\n",j);
		for(int k=0;k<10;k++)
		{
			if(B[k]>0)
			{
				for(int p=0;p<B[k];p++) printf("%d",k);
			}
		}
		printf("\n");
	}
	return 0;
}