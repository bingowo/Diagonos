#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char a[1001];
	scanf("%s",a);
	long long b;
	int l=strlen(a);
	if(l==1) {printf("1");return 0;}
	else if(l==2)
	{
		if(a[0]==a[1]) printf("1");
		else printf("4");
		return 0;
	}
	else if(l>2)
	for(int i=0;i<l;i++)
	{
		if(i==0)
		{
			if(a[0]!=a[1]) b=2;
			else if(a[0]==a[1]) b=1;
		}
		else if(i==l-1) 
		{
			if(a[l-1]!=a[l-2]) b*=2,b%=1000000007;
		}
		else 
		{
			if(a[i]==a[i-1]&&a[i]!=a[i+1]) b*=2,b%=1000000007;
			else if(a[i]!=a[i-1]&&a[i]==a[i+1]) b*=2,b%=1000000007;
			else if(a[i]!=a[i-1]&&a[i]!=a[i+1])
			{
				if(a[i-1]==a[i+1]) b*=2,b%=1000000007;
				else if(a[i-1]!=a[i+1]) b*=3,b%=1000000007;
			}
		}
	}
    printf("%d",b);
	printf("\n");
	return 0; 
}