#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>

int main()
{
	char ord[110];
	scanf("%s",ord);
	int l=strlen(ord);
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		long long x=0,y=0;
		long long qus[2];
		scanf("%lld%lld",&qus[0],&qus[1]);
		int k;
		for(int kk=0;kk<100;kk++)
		for(k=0;k<l;k++)
		{
			if(x==qus[0]&&y==qus[1]) break;
			if(ord[k]=='U') y++;
			else if(ord[k]=='D') y--;
			else if(ord[k]=='L') x--;
			else if(ord[k]=='R') x++;
		}
		if(k>=l) printf("No\n");
		else printf("Yes\n");
		
	}
	return 0;
}