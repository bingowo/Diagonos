#include<stdio.h>
#include<string.h>

void out (long long x)
{
	if(x==1)
		puts("i");
	else if(x==-1)
		puts("-i");
	else
		printf("%lldi\n",x);
}
int main()
{
	int table[][2]={{1,0},{-1,1},{0,-2},{-2,2}};//(-1+i)的0到3次方
	//（-1+i）每4次一循环，二进制也是4位一个16进制数
	char s[1005]={0};
	scanf("%s",s);
	int len = strlen(s);
	long long int a=0,b=0,tem = 1;
	
	for(int i=len-1;i>=2;i--)
	{
		int num = 0;
		if(s[i] >= 'A' && s[i] <= 'F')
			num = s[i] - 'A' + 10;
		else
			num = s[i]-'0';
		for(int j=0;j<=3;j++)
		{
			if(num & 1)
			{
				a = a + tem * table[j][0];
				b = b + tem * table[j][1];
			}
			num >>= 1;//num/=2;
		}
		tem = tem * (-4);//(-1+i)^4 == -4
	}
	if(b == 0)
		printf("%lld",a);
	else if(a == 0)
		out(b);
	else if(b < 0)
		printf("%lld",a),out(b);
	else
		printf("%lld+",a),out(b);
	
	return 0;
}