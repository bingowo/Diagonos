#include <stdio.h>


int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		
		printf("case #%d:\n",i);
		printf("%d\n",n/5+n/25+n/125+n/625);
	}
	return 0;
}