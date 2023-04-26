#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char w[1010];
	scanf("%s",&w);
	long long int M=1000000007;
	long long int r=1;
	if(strlen(w)==1) 
	{
		printf("1");
		return 0;
	}
	else if(strlen(w)==2)
	{
		if(w[0]==w[1]) printf("1");
		else printf("4");
		return 0;
	}
	else
	{
		
		if(w[0]!=w[1]) r=2;
		int i=1;
		for(;i<strlen(w);i++)
		{
			int a=3;
			if(w[i]==w[i-1]) a--;
			if((w[i]==w[i+1])&&(i<strlen(w)-1)) a--;
			if(i==(strlen(w)-1)) a--;
			r=(r%M)*(a%M)%M;
		}
		printf("%lld",r);
		return 0;
	}
	printf("%lld",r);
	return 0;
}
