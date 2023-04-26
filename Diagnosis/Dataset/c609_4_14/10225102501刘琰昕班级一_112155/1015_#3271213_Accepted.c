#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long x, p;
int num[100005],top=0,flg=1,mov=0;

int main()
{
	scanf("%lld%lld",&x,&p);//分子分母
	if(x<0) flg = -1, x = -x;//符号位提出
	while(x>0)
    {
		num[++top] = x % 3;
		x /= 3;
	}//分解成三进制 
	while(p>1) p/=3,mov++;//小数位 
	for(int i=1;i<= top; i++)
	{
		num[i] ++;
		num[i+1] += num[i] / 3;
		num[i] %= 3;
	}
	for(int i = 1; i <= top; i ++) num[i] --;//由题意生成平衡三进制数 
	if(num[top + 1] > 0) num[top ++];//最高位可能进位 
	if(flg == -1)
		for(int i = 1; i <= top; i ++) num[i] =- num[i];//在这里让每位都变负，可以正常输出 
	int les = 1;
	while(les <= top && num[les] == 0) les ++;// 去除尾部0，记录位置 
	if(les > top) putchar('0'), exit(0);//特判，输出0 
	if(mov >= top) {//小于1 
		printf("0.");
		for(int i = mov - top; i >= 1; i --) putchar('0'); 
		for(int i = top; i >= les; i --) printf("%d", num[i] == -1 ? 2 : num[i]);
	} else {//大于1 
		for(int i = top; i > mov; i --) printf("%d",num[i] == -1 ? 2 : num[i]);
		if(les <= mov) {
			putchar('.');
			for(int i = mov; i >= les; i --) printf("%d",num[i] == -1 ? 2 : num[i]);
		}
	}
	return 0;
}
