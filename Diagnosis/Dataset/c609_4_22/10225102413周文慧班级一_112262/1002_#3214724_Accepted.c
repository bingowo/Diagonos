#include<stdio.h>
int reverse(int n)//转换为二进制
{
	int s[32]={0};//将s中的32位都初始化为0
	int len;//记录二进制总位数，其实直接用strlen也可以
	for(int i=0;i<32;i++)
	{
		if(n>1)
		{
			s[i]=n%2;//取余数
			n=n/2;
		}
		else//0和1可以直接计入
		{
			s[i]=n;
			len=i+1;
			break;//终止循环
		}
	}
	int max=1, a=1;//max就是最长非重复长度，a是帮助储存（上一轮）长度的
	for(int j=0;j<len;j++)
	{
		if((s[j]!=s[j+1])&&(j<(len-1)))
		{
			a++;
			if (a>max)
			{
				max=a;
			}
			continue;
		}
		if((j<len)&&(s[j]==s[j+1]))
		{
			a=1;
			continue;
		}
		if(j==len)
			break;
	}
	return max;
}
int main()
{
	int n,T;
	int max;
	int i=0;
	scanf("%d",&T);
	for (;T>0;T--,i++)//循环输入-二进制转换-输出
	{
		scanf("%d",&n);
		max=reverse(n);
		printf("case #%d:\n",i);
		printf("%d\n",max);
	}
}