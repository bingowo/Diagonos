#include <stdio.h>
int T;
int main(void)
{
	scanf("%d",&T);
	while(T--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		int cnt = 0;
		for(int i=0;i<32;i++)
		{
			if((x&1)!=(y&1)) cnt++;
			x = x>>1;
			y = y>>1;
		}
		printf("%d\n",cnt);
	}
	return 0;
}