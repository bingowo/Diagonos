#include <stdio.h>
#include <stdlib.h>
/*
T:测试数据组数
N：待转换数字
R：目标进制 
*/ 
int main()
{
	int T;
	scanf("%d",&T);
	do
	{
		int N,R;
		scanf("%d%d",&N,&R);
		baseconvertion(N,R);
	}while(T--);
	return 0;
}

int baseconvertion(N,R)
{
	char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int ans[32];//存放结果 
	int pl;//pl:目标进制每一位上的十进制值
	int sign=1;//sign：用于判断N的正负；
	int remain=N;//减去余数后剩下的值
	int anspla=0;//ans的下标 
	if( N<0 )
	{
		sign=-1;
	 } 
	do
	{
		pl=remain%R;
		remain=(remain-pl)/R;
		ans[anspla++]=pl; 
	 } while (remain>0);
	if ( sign == -1 )
	{
		printf("-");
	}
	for (;anspla>=0;anspla--)
	{
		printf("%c",table[ans[anspla]]);
	}
	printf("\n");
	return 0;
}