//十进制转平衡三进制（全部>=0)
#include <stdio.h>

int len=0;
int res[1000005]={0};
char ans[1000005]={0};

int count (int a ,int b)
{
	int count=0;
	while(a)
	{
		a/=b;
		count++;
	}
	return count;
}
void trans(int x,int y)
{
	while(x)
	{
		res[len]= x % y;
		x /= y;
		len++;
	}
}
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	
	int ret1 = m / n,ret2 = m % n,mov = count(n,3) - 1;
	//ret1是整数部分，ret2是小数部分，mov是小数位数
	
	//开始转换
	if(mov!=0)
	{
		trans(ret2,3);
	}
	trans(ret1,3);
	int flag=0;
	
	for(int i=0;i<len;i++)
	{
		res[i] = res[i] + flag + 1;
		flag = 0;
		if(res[i] >= 3)
			res[i] -= 3,flag = 1;
//		printf("%d",res[i]);
	}
	if(flag == 1)//最后一位要进位
		res[len++] = 2;

	for(int i=0;i<len;i++)
	{	
		res[i] -= 1;
		if(res[i] == -1)
			ans[i] = '2';
		else
			ans[i] = res[i] + '0';
	}
	
	//输出
	int x=0;
	//先去掉开头和末尾的0
	while(ans[x]=='0')	x++;
	while(ans[len-1]=='0' && len > mov + 1 )	len--;
	
	for(int i=len;i>=x;i--)
	{
		if(i == mov-1)
			putchar('.');
		printf("%c",ans[i]);
	}
	putchar('\n');
	
	return 0;
}