#include <stdio.h>
int main()
{
	int a, b; //   a/b
	scanf("%d %d", &a, &b);
	if (a == 0) printf("0\n");
	else
	{
		int flag = 1;//表示a的符号,1代表正，-1代表负
		if (a < 0)
		{
			a = -a;  flag = -1;
		}
		int temp[10000];//存储a的三进制表示
		int i = 0;
		do {
			temp[i++] = a % 3;
			a /= 3;
		} while (a > 0);
		temp[i + 1] = 0;
		int up = 0,k = 0;
		while (k < i)	//将temp中的元素＋1
		{
			int t = temp[k] + 1 + up;
			temp[k] = t % 3;
			up = t / 3;
			k++;
		}
		int out;//计算最高位是否需要进位
		if (up)
		{
			temp[k] = 1 * flag;
			if (temp[k] == -1) temp[k] = 2;
			out = k;
		}
		else out = k - 1;
		//将temp中所有元素-1得到a-1的三进制表示
		for (int i = 0; i < k; i++)
		{
			temp[i]--;
			if (flag == -1) temp[i] = -1 * temp[i];
			if (temp[i] == -1) temp[i] = 2;
		}
		int mov = 0;//计算b的三进制表示的小数点位置
		while (b > 1)
		{
			b /= 3;
			mov++;
		}
		//计算a-1的三进制表示的小数点前0的个数
		int fl = 0;
		for (; fl < out; fl++)
		{
			if (temp[fl] != 0) break;
		}
		if (mov > out) printf("0");
		//整数部分
		for (; out >= mov; out--)
			printf("%d", temp[out]);
		if (mov > fl) printf(".");
		//小数部分
		for (int i = mov - 1; i >= fl; i--)
			printf("%d", temp[i]);
	}
	return 0;
}