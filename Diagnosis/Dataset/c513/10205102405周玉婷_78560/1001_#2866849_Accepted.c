#include <stdio.h>//进制转换 
int main()
{
	char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";//建立映射关系 
	char temp[32];//用来存储转换成R进制后各位的数，储存进去的是倒置的，31是最大的数转换成2进制后的位数 
	int t,n,r;// 分别是组数，10进制数，r进制数 
	scanf("%d",&t); 
	while(t-->0)//循环，每组数据的计算 
	{
	scanf("%d %d",&n,&r);
    int i=0,flag=0;//i用于向temp存数据，同时记录输入了多少个，flag判断符号 
	if(n<0) 
	{ flag=1;n=-n;}
	do temp[i++]=table[n%r];
	while(n=n/r); 
	if(flag) printf("-");
	for(i=i-1;i>=0;i--)//逆序输出 
	printf("%c",temp[i]);
	printf("\n");
	}
	return 0;
}