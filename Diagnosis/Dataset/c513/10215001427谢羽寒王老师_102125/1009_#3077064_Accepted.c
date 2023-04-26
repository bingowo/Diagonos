#include <stdio.h>
#include <string.h>
int gcd(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int T;
	scanf("%d", &T);
	getchar();
    for(int i = 0; i < T; ++i) {
		char s[200];
		gets(s);
        int top = 0, btm = 0;  //top记入1的个数，btm记录总位数
		for(int i = 0, l = strlen(s); i < l; ++i) {
			unsigned char ch = s[i];         //s的每一位 分别转换成他的十进制
			while(ch != 0) {
                top += (ch & 1);      //通过二进制的按位与运算 得到最小位为0或1 相加从而得到1的个数
                ch >>= 1;               //依次进行
            }
            btm += 8;         //每做一个s[i] 总位数加8 ascii码最大为127 2的7次方是128
		}
        int g = gcd(top, btm);
        printf("%d/%d\n", top / g, btm / g);
    }
    return 0;
}