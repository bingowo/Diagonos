#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int t;
	scanf("%d",&t);
	int j = 0;
	for(; j < t; j++)
	{
		int cnt = 0;
		int n;
		scanf("%d",&n);
		int len = 0;//求二进制长度
		int i;
		for(i = 0;i<31;i++)
		{
			if(n - pow(2,i) <= 0)
				len = i + 1;
		} 
		
		for(i = 0;i < len - 1;i++)
		{
			if((n>>i)&1 != (n>>(i+1))&1)
				cnt++;
		}
		
		
		printf("case #%d:\n",j);
		printf("%d\n",cnt);

	}
} 