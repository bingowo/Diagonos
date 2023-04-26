#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//八进制转十进制
int main()
{
	int T;
	scanf("%d",&T);
	for(int t = 0;t<T;t++)
	{
		int numbers = 0,temp; 						//numbers 记录当前十进制小数位数
		char Octal[52] = {'0'},decimal[155] = {0};
		scanf("%s",Octal);
		int len=strlen(Octal) - 1;
		
		for(;len != 1;len--){					//从八进制小数最后一位开始向前循环
			int digit = Octal[len] - '0';		//digit 初始化为八进制当前数码，后续作余数
			
			int j=0;						//进入高精度除法(长除法)，temp 存储被除数

			do{
				if(j < numbers)
					temp = digit*10 + decimal[j]-'0';  //与上一位八进制 相加后再/8，才能使后面的八进制位是8^（-n）
				else
					temp = digit*10;
				decimal[j++] = temp / 8 +'0';	//计算商，并且更新十进制小数当前位
				digit = temp % 8;				//计算上一位的余数
			}while( digit != 0 || j < numbers);	//余数为零且循环超过十进制小数位数时停止
			numbers = j;						//更新十进制位数
			
		}
		decimal[numbers] = '\0';				//字符串末尾置 ’\0’
		
		printf("case #%d:\n",t);
		printf("0.%s\n",decimal);
	}
	return 0;
}

