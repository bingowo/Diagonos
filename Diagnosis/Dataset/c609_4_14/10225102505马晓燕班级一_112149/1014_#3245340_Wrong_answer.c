//十进制转平衡三进制（全部>=0)
#include <stdio.h>

int len=0;
int res[10000005]={0};
//char ans[10000005]={0};

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
	
	if(m == 0)
	{
		printf("0\n");
		return 0;
	}
	
	int ret1 = m / n,ret2 = m % n,mov = count(n,3) - 1;
	//ret1是整数部分，ret2是小数部分，mov是小数位数
	
	//开始转换
	if(ret2!=0)
	{
		trans(ret2,3);
	}
	trans(ret1,3);
	
	if(len <= mov && ret2 != 0)
		len = mov + 1;
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
			res[i] = 2;
		
	}
	
	//输出
	int x=0;
	//先去掉开头和末尾的0

	if(ret2 != 0)
		while(res[x]==0 && x < mov )	
			x++;
	while(res[len]==0 && len > mov + 1 )	
		len--;
	
	for(int i=len;i>=x;i--)
	{
		if(i == mov-1 && ret2 != 0)
			putchar('.');
		printf("%d",res[i]);
	}
	printf("\n");
	
	return 0;
}