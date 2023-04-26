#include <stdio.h>
int T;
int main(void)
{
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++)
	{
		int x;
		scanf("%d",&x);
		int res = 0;
		int bit[50] = {0};
		int len = 0;
		while(x)
		{
			if(x&1) bit[len] = 1;
			else bit[len] = 0;
			len++;
			x = x>>1;
		}
		len--;
		for(int i=0;i<=len;i++)
		{
			int cnt = 0;
			while(i+cnt+1<=len && bit[i+cnt]!=bit[i+cnt+1]) cnt++;
			if(cnt+1 > res) res = cnt+1;
		}
		printf("case #%d:\n",kase);
		printf("%d\n",res);
	}
	return 0;
}