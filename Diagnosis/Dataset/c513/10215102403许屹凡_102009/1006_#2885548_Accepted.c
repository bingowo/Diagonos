#include <stdio.h>

int main()
{
	int T,i;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{	char s[20];
		scanf("%s",s);
		unsigned int p=0;
		long long ans=0;
		for (;p<strlen(s); p++) {
			ans *= 3;
			if (s[p]=='1') ans += 1;
			if (s[p]=='-') ans -= 1;
		}
		printf("case #%d:\n%lld\n",i,ans);
	}
	return 0;
}