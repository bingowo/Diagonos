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
		int x , y , p = 0 , q = 0;
		scanf("%d %d",&x,&y);
		
		int a[100] = {0} , b[100] = {0};//转换成二进制
		while(x != 0)
		{
			a[p] = x%2;
			p++;
			x /= 2;
		}	
		
		while(y != 0)
		{
			b[q] = y%2;
			q++;
			y /= 2;
		}	
		
		int max = p > q ? p : q;
		int cnt = 0 , i;
		for(i = 0 ; i < max; i++)
		{
			if(a[i] != b[i])
				cnt++;
		}
		
		printf("%d\n",cnt);
	}
	
	return 0; 
}
