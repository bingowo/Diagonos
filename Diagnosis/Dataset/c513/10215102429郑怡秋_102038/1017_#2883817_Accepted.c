#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int main()
{
	char A[60];
	scanf("%s",A);
	int l=strlen(A),y=0;
	long long B[60];
	long long k=1;
	for(int i=0;i<l;i++)
	{
		if(A[i]=='(') k*=1000;
		else if(A[i]==')') k/=1000;
		if(A[i]!='('&&A[i]!=')')
		{
			if(A[i]=='I') B[y]=1;
			else if(A[i]=='V') B[y]=5;
			else if(A[i]=='X') B[y]=10;
			else if(A[i]=='L') B[y]=50;
			else if(A[i]=='C') B[y]=100;
			else if(A[i]=='D') B[y]=500;
			else if(A[i]=='M') B[y]=1000;
			B[y]*=k;y++;
		}
	}
	long long ans=0;
	for(int i=0;i<y-1;i++)
	{
		if(B[i]<B[i+1]) ans-=B[i];
		else ans+=B[i];
	}
	ans+=B[y-1];
	printf("%lld\n",ans);
	return 0;
}