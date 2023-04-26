#include <stdio.h>

/**
 * 题目要求：有一个正整数数组，包含N个元素，要求编程求出其中的素数之和以及所有素数的平均值
 *
 * 素数：即在正整数中，除了1与本身之外没有其他约数的数（1除外）
 *
 **/
int main(int argc,char *argv[])
{
	int a[100],i,j,s,count=0;
	
	float sum=0;
	
	for(i=0;i<100;i++)
	{
		a[i]=i+1;
	}
	
	for(i=0;i<5;i++)
	{
		// s 等于零就代表是素数
		s=0;
		
		for(j=2;j<=a[i];j++)
		{
			
			if(a[i]==j)
			{
				// 等于本身跳出此次循环
				continue;
			}
			else
			{
				if((a[i]%j)==0)
				{
					// i能被任何一个数（不是1或者本身）整除，就是不是素数
					s=1;
					break;
				}
			}
		}
		
		if(s==0)
		{
			printf("素数%d\n",a[i]);
			count++;
			sum+=a[i];
		}
	}
	
	
	printf("count = %d \n",count);
	printf("sum = %.2f \n",sum);
	printf("avreage = %-10.2f \n",(float)(sum/count));
	
	return 0;
}
