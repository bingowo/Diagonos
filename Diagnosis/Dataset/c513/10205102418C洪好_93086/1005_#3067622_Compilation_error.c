//八进制octal小数：0.01234567 转为十进制decimal小数：
//(((((((7/8+6)/8+5)/8+4)/8+3)/8+2)/8+1)/8+0)/8 
/*
7/8=0.875
(6+0.875)/8=0.859375
(5+0.859375)/8=0.732421875
(4+0.732421875)/8=0.591552734375
*/
/*
6.875/8:
被除数div            商quo  余数rem 
(6×10 + 8) ÷ 8   =   8 …… 4
(4×10 + 7) ÷ 8   =   5 …… 7
(7×10 + 5) ÷ 8   =   9 …… 3
(3×10 + 0) ÷ 8   =   3 …… 6
(6×10 + 0) ÷ 8   =   7 …… 4
(4×10 + 0) ÷ 8   =   5 …… 0
*/

#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d",&t);
	int k;
	for(k=0;k<t;k++)
	{
		char oct[51],dec[149];
		scanf("%s",oct);
		int len=strlen(oct);  //八进制小数总长度
		int i; 
		int div,quo,rem;  //被除数加上上一位再除以8
		quo=oct[len-1]-'0';
		for(i=len-2;i>1;i--)
		{
			div=rem*10+oct[i]-'0';
		}
		printf("case #%d:\n",k);
		printf("%d\n",);
	}
} 