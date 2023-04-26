#include <stdio.h>
#include <string.h>
int main()
{
	int t;
	scanf("%d",&t);
	int i=0;
	for(i;i<t;i++)
	{
		char m[50];
		scanf("%s",m);
		int k;
		double sum=0;
		k=strlen(m)-1;
		for(k;k>1;k--)
		{
			sum=(m[k]-'0'+sum)/8;
		}
		printf("case #%d:\n",i);
		printf("%lf\n",sum);
		
		
	}
	return 0;
}