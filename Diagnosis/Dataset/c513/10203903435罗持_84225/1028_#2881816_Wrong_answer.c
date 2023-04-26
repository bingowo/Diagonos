#include <stdio.h>
#include <string.h>
#include <stdio.h>
int main(void)
{
	int table[1010] = {0};
	char c;
	scanf("%c",&c);
	int x;
	while(scanf("%d",&x)!=EOF)
	{
		table[x]++;
	}
	if(c=='A')
	{
		for(int i=1;i<=1000;i++)
		{
			if(table[i]) printf("%d ",i);
		}
	}
	else
	{
		for(int i=1;i<=1000;i++)
		{
			if(table[i]) printf("%d ",i);
		}
	}
	return 0;
}