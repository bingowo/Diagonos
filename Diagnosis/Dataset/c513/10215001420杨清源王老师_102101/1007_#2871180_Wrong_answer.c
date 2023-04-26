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
		int n , i;
		scanf("%d",&n);
		
		int a[100];//转换成二进制
		while(n != 0)
		{
			a[cnt] = n%2;
			cnt++;
			n /= 2;
		}
		
		
//		for(i = cnt - 1;i >= 0;i--)
//			printf("%d ",a[i]);
//        printf("\n");
		
		int tmp = 1;
		int max = tmp;
		
		for( i = 1; i < cnt; i++)
		{
			if(a[i] != a[i-1])
				tmp++;
			else
			{
				
				tmp = 0;
				continue;
			}
			
			if(max < tmp)
				max = tmp;
		}
		
		
		printf("case #%d:\n",j);
		printf("%d\n",cnt);

	}
} 