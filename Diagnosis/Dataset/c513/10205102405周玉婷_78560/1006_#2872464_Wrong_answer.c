#include<stdio.h>
#include<string.h>
#include<limits.h> 
int main()
{
	int t;
	scanf("%d",&t);
	for (int i=0;i<t;i++)//循环次数 
	{
		char str[30];//xxxxxxxxxxxxx之前开成INT_MAX，要根据题目开，用数学知识 ，但为啥会蹦掉？ 
		int num[30];
		scanf("%s",str);
		for(int j=0;str[j];j++)//将平衡三进制换为对应的数字 
		{
			if(str[j]=='1') num[j]=1;
			else if(str[j]=='-') num[j]=-1;
			else  num[j]=0;
		}
		int  len=strlen(str);//统计一共输入了多少个字符 
		int sum=0;
		for(int j=0;j<len;j++)//用霍纳原则计算 
		{
			sum=sum*3+num[j];
		}
		printf("case #%d:\n%d",i,sum);
	}
	return 0;
}