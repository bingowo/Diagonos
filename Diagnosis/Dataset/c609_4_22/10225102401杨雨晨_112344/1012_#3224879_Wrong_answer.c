#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	int t,i,p;
	long double m=0;
	char s[100];
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{	m=0;
		scanf("%s",s);
		for (p=2;p<strlen(s);p++)
		{
			m+=(s[p]-'0')*pow(8,1-p);
		}
		printf("case #%d:\n",i);
		printf("%.100lf\n",m);
		
	}
	return 0;
}