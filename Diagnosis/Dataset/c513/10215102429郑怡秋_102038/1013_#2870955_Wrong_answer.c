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
	int A=0,B=0,C=1;
	while(*p && *p!='.') p++,j++;
	while(S[0]!='0' && j>0)
	{
		if(*(p-l)=='2') m=-1;
		else if(*(p-l)=='0') m=0;
		else if(*(p-l)=='1') m=1;
		A+=m*pow(i);
		i++;j--;l++;
	}
	if(*p=='.')
	{
		p++;
		while(*p)
		{
			if(*p=='2') m=-1;
			else if(*p=='0') m=0;
			else if(*p=='1') m=1;
			B=B*3+m;
			C*=3;
			p++;
		}
	if(B<0 && A>0) {B=C+B;A--;}	
	else if(B<0 && A<=0) B=-B;
	else if(B>0 && A<=0) {A++;B=C-B;}
	}
	if(A==0) printf("%d %d",B,C);
	else if(B==0) printf("%d",A);
	else printf("%d %d %d",A,B,C); 
	return 0;
 } 