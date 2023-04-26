#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		char A[510];
		scanf("%s",A);
		char B[50];
		int C[50]={0};
		int m=0;
		for(int j=0;j<strlen(A);j++)
		{
			B[m]=A[j];
			if(A[j]!='\n'&&A[j]==A[j+1]&&C[m]<254) C[m]++;
			else m++;
		}
		printf("case #%d:\n",i);;
		for(int j=0;j<m;j++)
		{
			printf("%d%c",C[j]+1,B[j]);
		}
		printf("\n");
	}
	return 0;
}