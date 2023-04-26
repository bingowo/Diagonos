#include<stdio.h>
#include<string.h>
int main()
{
	char Octal[55], decimal[155];
	int numbers = 0;  //numbers 记录当前十进制小数位数
	int len;
	len = strlen(Octal)-1;
	for (; len != 1; --len)  //从八进制小数最后一位开始向前循环
	{
    	digit = Octal[len] - '0';  //digit 初始化为八进制当前数码，后续作余数
    	j = 0;
    	do 
		{   //进入高精度除法，temp 存储被除数
       		if (j < numbers)
           		temp = digit*10 + decimal[j] - '0';
       		else  //超过十进制小数位数直接下 0
           		temp = digit*10;
       		decimal[j++] = temp/8 + '0';  //计算商，并且更新十进制小数当前位
 	   		digit = temp%8;  //计算余数
   		} while (digit!=0 || j < numbers);  //余数为零且循环超过十进制小数位数时停止
    	number = j;  //更新十进制位数
	}
	decimal[numbers] = '\0';  //字符串末尾置 '\0'

//	/*
	int t;
	scanf("%d",&t);
	int c,i,j=0;
	for(c=0;c<t;c++)
	{
		char f[55];
		scanf("%s",f);
		int len=strlen(f);
		int oct[55];
		for(i=len-1;i>=2;i--)
		{
			oct[j++]=f[i]-'0';  //octal：从8进制小数最后一位开始存 
			//printf("%d\n%c\n",octal[i],f[l]);
			//printf("%c\n",f[l-1]);
			//l--;
		}
		oct[]
		int yu=oct[0];
		dec[]
	}
//	*/
	return 0;
} 