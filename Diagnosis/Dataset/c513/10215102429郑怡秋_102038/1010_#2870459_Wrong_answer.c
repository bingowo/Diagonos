#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void itob(int n,int x)
{
	int i=0;
	while(i<x)
	{
		printf("%d",(n>>(x-i-1))&1);
		i++;
	}
}


int main()
{
	char A[600];
	scanf("%s",A);
	printf("0001");
	int l=strlen(A);
	int re=l%3;
	int i;
	itob(l,10);
	for(i=0;i<l-re;i+=3)
	{
		int k=0;
		for(int j=0;j<3;j++)
		{
			k=10*k+A[j+i]-'0';
		}
		itob(k,10);
	}
	int p=0;
	for(int b=re;b>0;b--)
	{
		p=10*p+A[l-b]-'0';
	}
	itob(p,1+re*3);
	return 0;
 } 