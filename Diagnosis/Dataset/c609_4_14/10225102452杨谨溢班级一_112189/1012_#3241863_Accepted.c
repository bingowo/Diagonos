# include <stdio.h>
# include <stdlib.h>
# include <string.h>
// 由于数据精度太高 无法使用double计算表示 利用数组进行计算
// 方法一：
/*int main()
{
	int cases;
	scanf("%d\n", &cases);
	for (int cas = 0; cas < cases; ++cas)
	{
		char ba[55] = { 0 };
		scanf("0.%s", ba);
		int length = strlen(ba);
		char ans[155] = { 0 };//最终结果
		char temp[155] = { 0 };//八的位数*基数
		char res[155] = {5,2,1};//八的基数
		for (int i = 0; i < length; ++i)
		{
			int wei = ba[i];
			
		}
		printf("case #%d:", cas);

	}
	return 0;
}*/

int main()
{
	int cases;
	scanf("%d\n", &cases);
	for (int cas = 0; cas < cases; ++cas)
	{
		char ba[55] = { 0 };  // 存储八进制小数
		char decimal[155] = { 0 }; // 存储十进制小数
		scanf("%s", ba);
		int temp;
		int numbers = 0;  // 记录当前十进制小数位数 第一次计算时 小数位数为 0 decimal 中没有数据
		int len = strlen(ba) - 1;
		for (; len>1; --len) // 从八进制小数最后一位开始向前循环
		{
			int digit = ba[len] - '0';  // digit 初始化为八进制当前数码 ，后续作为余数
			int j = 0;  // 记录当前十进制计算位数 
			do  // 进入高精度除法 temp 储存被除数
			{
				if (j < numbers)
					temp = digit * 10 + decimal[j] - '0';
				else
					temp = digit * 10;  // 相当于补零 之后再继续除法计算
				decimal[j++] = temp / 8 + '0'; // 计算商 并更新十进制小数当前位  但之后的数据依旧为上次计算后的数据
				digit = temp % 8; // 计算余数
			} while (digit != 0 || j<numbers);  // 余数更新为0 循环超过十进制小数位数时停止
			numbers = j; //更新十进制位数  在经过初次计算后 十进制小数出现了 numbers不再是0
		}
		decimal[numbers] = 0;   //字符串末尾 为 \0  可以摒弃无用数据
		printf("case #%d:\n", cas);
		printf("0.%s\n", decimal);
	}
	return 0;
}