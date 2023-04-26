#include <stdio.h>
#include <string.h>
int gcd(int a, int b)      //a是top，b是bottom
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
	scanf("%d", &T);               //题目数
	getchar();                     //跳过换行符
    for(int i = 0; i < T; ++i) {
		char s[200];               //每次循环重新定义该字符数组
		gets(s);
        int top = 0, btm = 0;    //分子分母，bottom
		for(int i = 0, l = strlen(s); i < l; ++i) {
			unsigned char ch = s[i];
			while(ch != 0) {          //当字符不为空字符时
                top += (ch & 1);      //
                ch >>= 1;          //ch = ch>>1;需求字符的二进制表示不断右移，每次判断最右边一位
            }
            btm += 8;
		}
        int g = gcd(top, btm);
        printf("%d/%d\n", top / g, btm / g);
    }
    return 0;
}
