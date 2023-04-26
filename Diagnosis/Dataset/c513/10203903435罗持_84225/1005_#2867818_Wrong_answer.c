#include <stdio.h>
#include <string.h>
int T;
int main(void)
{
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++)
	{
		char s[60] = {0};
		scanf("%s",s);
		int len = strlen(s);
		double res = 0;
		long long weigh = 1;
		for(int i=2;i<len;i++)
		{
			res = res*8+(s[i]-'0');
			weigh *= 8;
		}
		printf("case #%d:\n",kase);
		printf("%f\n",res/weigh);
	}
	return 0;
}