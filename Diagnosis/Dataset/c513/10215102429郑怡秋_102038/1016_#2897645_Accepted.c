#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h> 

int main()
{
	int n,r;
	scanf("%d%d",&n,&r);
	char A[100];
	int i=0,k=0;
	if(n==0) A[k++]='0';
	while(n)
	{
		i=n%r;n/=r;
		if(i<0) i-=r,n+=1;
		if(abs(r)<=10) A[k]=i+'0';
		else if(abs(r)>10)
		{
			if(i<10) A[k]=i+'0';
			else if(i>=10) A[k]=i-10+'A';
		}//printf("%c\n",A[k]);
		k++;
	}
	for(int j=k-1;j>=0;j--)
	{
		printf("%c",A[j]);
	}
	printf("\n");
	return 0;
}