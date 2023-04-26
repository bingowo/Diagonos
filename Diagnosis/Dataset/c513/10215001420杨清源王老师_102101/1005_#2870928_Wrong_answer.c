#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int t;//问题数
	int j = 0;
	scanf("%d",&t);
	for(; j < t; j++)
	{
		char O[100];//储存八进制 
		scanf("%s",O);
		int digit = strlen(O) - 2;//记录八进制小数点后共有几位 
		double sum = 0; 
		int tmp = 0;
		for(;digit != 0; digit--)
		{
			tmp = O[digit+1] - '0';
			sum = sum/8 + tmp;
		}
		sum = sum/8;
		printf("case #%d:\n",j);
		printf("%lf\n",sum);
	}
	
	return 0;
}