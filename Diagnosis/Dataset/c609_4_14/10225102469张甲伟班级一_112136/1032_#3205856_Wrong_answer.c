#include <stdio.h>
#include<stdlib.h>
int T,a[1000001],cnt,maxn,i;
long long sum;
char s[100];
int main()
{
	scanf("%s",s);
	maxn=1,cnt=1;
	for(int i=1;s[i]!='\0';i++)
	{
		if(s[i]!=s[i-1])
			cnt++;
		else
		{
			if(maxn<cnt)
				maxn=cnt;
			cnt=1;
		}
	}
	printf("%d",maxn);
	return 0;
}