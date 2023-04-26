#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int pow(int x)
{
	if(x==0) return 1;
	int ans=1;
	int i;
	for(i=0;i<x;i++) ans*=3;
	return ans;
}
int main()
{
	char S[100];
	scanf("%s",S);
	char* p=S;
	int k=strlen(S);
	int m=0;
	int i=0,j=0,l=1;
	int A=0,B=0,C=0;
	while(*p && *p!='.') p++,j++;
	while(j>0)
	{
		if(*(p-l)=='2') m=-1;
		else if(*(p-l)=='0') m=0;
		else if(*(p-l)=='1') m=1;
		A+=m*pow(i);
		i++;j--;l++;
	}
	printf("%d",A);
	return 0;
 } 