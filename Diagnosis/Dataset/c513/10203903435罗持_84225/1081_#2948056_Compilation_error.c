#include <stdio.h>
int T;
const int len = 1000;
int main(void)
{
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++)
	{
		int a,n;
		scanf("%d %d",&a,&n);
		cin >> a >> n;
		int num[len] = {0};
		num[len-1] = 1;
		while(n--)
		{
			for(int i=len-1;i>=0;i--)
				num[i] *= a;
			for(int i=len-1;i>=0;i--)
			{
				if(num[i]>9)
				{
					num[i-1] += num[i]/10;
					num[i] %= 10;
				}
			}
		}
		int st;
		for(int i=0;i<len;i++)
		{
			if(num[i]==0 && num[i+1]!=0)
			{
				st = i+1;
				break;
			}
		}
		printf("case #%d:\n",kase);
		for(int i=st;i<len;i++) printf("%d,num[i]);
		putchar('\n');
	}
	return 0;
}