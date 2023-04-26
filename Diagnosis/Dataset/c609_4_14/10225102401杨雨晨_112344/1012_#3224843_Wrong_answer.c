#include <stdio.h>
#include <string.h>
int main()
{
	int t,i,p;
	double m=0;
	char s[100];
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{
		scanf("%s",s);
		for (p=2;p<strlen(s);p++)
		{
			m+=s[p]-'0';
			m=m/8.0;
		}
		printf("case #%d:\n",i);
		printf("%lf",m);
		
	}
	return 0;
}