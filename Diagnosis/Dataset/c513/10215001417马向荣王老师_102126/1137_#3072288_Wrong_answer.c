#include<stdio.h>
#include<string.h>
#define N 10000


int main()
{
	char num_1[N]={0},num_2[N]={0},result[N]={0};
	long len_1,len_2,len;
	int i; 
	 
	printf("请输入第一个数\n");
	scanf("%s",num_1);
	getchar();
	printf("请输入第二个数\n"); 
	gets(num_2);
	
	//计算两个数的位数以及结果的最大位数 
	len_1 = strlen(num_1);
	len_2 = strlen(num_2);
	len   = len_1>len_2? len_1:len_2 ;    
	len++;
	
	//倒序相加直到小的数被加完为止 
	for(i = 0;i<len_1&&i<len_2;i++)
	{
		result[len-1-i] = num_1[len_1-1-i] - '0' + num_2[len_2-1-i] - '0';
	}
	
	//找出大的数直接赋值进result 
	if(len_1>len_2)
	{
		for(;i<len_1;i++)
		{
			result[len-1-i] = num_1[len_1-1-i] - '0';
		}
	}
	else
	{
		for(;i<len_2;i++)
		{
			result[len-1-i] = num_2[len_2-1-i] - '0';
		}
	 }
	 
	//倒序判断，逢十进一
	for(i = len - 1;i>0;i--)
	{
		if(result[i]>=10)
		{
			result[i] = result[i]%10;
			result[i-1]++;
		}
	 }
	 
	 //判断是后位数多出一位 9+8=17变成2位数,如果没有则全部前移。并变回数字的ASC2码 
	 if(result[0]!= 0)
	 {
	 	for(i = 0;i<len;i++)
	 	{
	 		result[i] += '0';
		 }
		 result[len] = '\0';
	  }
	 else
	 {
	 	for(i=1;i<len;i++)
	 	{
	 		result[i-1] = result[i] + '0';
		 }
		 result[len-1] = '\0';
      }
      
      printf("两个数相加的结果是:\n");
      puts(result);
      
	 return 0;
 } 
