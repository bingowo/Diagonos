#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int f(char c)
{
	if(c=='{') return -1;
	else if(c=='[') return -2;
	else if(c=='(') return -3;
	else if(c==')') return 3;
	else if(c==']') return 2;
	else if(c=='}') return 1;
	else return 0;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		char A[101];
		scanf("%s",A);
		int l=strlen(A);
		int j=0;int m=0;
		int a=0,b=l-1,sum=0;
		for(int k=0;k<l;k++)
		{
			sum+=f(A[k]);
		}
		if(sum==0) m=0;
		else m=1;
		while(j<l)
		{
			if(A[j]=='{'&&(A[j+1]!='['&&A[j+1]!='}')) m=1;
			else if(A[j]=='['&&(A[j+1]!=']'&&A[j+1]!='(')) m=1;
			else if(A[j]=='('&&(A[j+1]!='{'&&A[j+1]!=')')) m=1;
			else if(A[j]=='}'&&A[j-1]!=']'&&A[j-1]!='{') m=1;
			else if(A[j]==']'&&A[j-1]!='['&&A[j-1]!=')') m=1;
			else if(A[j]==')'&&A[j-1]!='('&&A[j-1]!='}') m=1;
			if(m==1) break;
			j++;
		}
		if(m==1) printf("No\n");
		else if(m==0) printf("Yes\n");
	}
	return 0;
}