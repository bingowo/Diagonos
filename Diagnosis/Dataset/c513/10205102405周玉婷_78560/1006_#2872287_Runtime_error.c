#include<stdio.h>
#include<string.h>
#include<limits.h> 
int main()
{
	int t;
	scanf("%d",&t);
	printf("%d",t);
	for (int i=0;i<t;i++)//循环次数 
	{
		char str[INT_MAX];
		int num[INT_MAX];
		scanf("%s",str);
		for(int j=0;str[j];j++)//将平衡三进制换为对应的数字 
		{
			if(str[j]=='1') num[j]=1;
			else if(str[j]=='-') num[j]=-1;
			else  num[j]=0;
		}
		int  len=strlen(str);
		int sum=0;
		for(int j=0;j<len;j++)
		{
			sum=sum*3+num[j];
		}
		printf("case #%d:\n%d",i,sum);
	}
	return 0;
}