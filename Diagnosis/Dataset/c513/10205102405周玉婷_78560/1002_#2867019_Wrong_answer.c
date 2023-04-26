#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int t,time=0;//分别是总次数 ，第几次，统计是几进制base system 
	scanf("%d",&t);
	while(t--)
	{
		char s[62];//保存输入的符号 1~60位 
		scanf("%s",s);
		int bs=2,a[123];//最小进制，基础值 ;以ASCII码为下标的数组，用于确定符号对应的数据 
		memset(a, -1, 123 * sizeof(int)); //设置a[123]的初始值全为-1
		a[s[0]]=1;// 由第二条注释知一定有a[s[0]]=1，特殊，提出来 
		for(int i=1;s[i];i++)
		{
			if(a[s[i]]!=-1) continue;//相同符号为同一个数字 
			if(a[s[i-1]]==1) a[s[i]]=0;//第二个字符置0，较特殊 
			else a[s[i]]=bs++;//bs给符号赋值 ,同时记录进制 
		}
		int p=0,j=0;//p为结果 
		while(s[j])
		p=p*bs+a[s[j++]];//霍纳规则计算 
		printf("case #%d:\n%d",time++,p); 
		
	}
	return 0;
}