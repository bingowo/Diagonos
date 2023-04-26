#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//求最大公约数
int gcd(int a, int b) 
{
    if (b == 0) return a; l//若b等于0，则a就是最大公约数
    else return gcd(b,a % b);//否则继续求a和b的余数的最大公约数
}
//解决单个测试用例
void solve( ) 
{
    char s [ 122];
    int i, fz = 0, fm = 0, l,g;
    fgets(s，122，stdin);//读入一行字符串
    l = strlen(s) - l;//字符串长度（去掉换行符)
    fm = 8*l;l//计算分母
    for (i = 0; i < l; i++) 
    {//遍历每个字符
        unsigned char c = s[i];
        while (c > 0) 
        {
            if (c & 1) fz++;l//若当前位为1，则分子加1
            c >>= l; l//右移一位，判断下一位
        }
    }
    g = gcd ( fm，fz);//求最大公约数
    printf ( "%d /%d\n" , fz / g, fm / g); //输出结果
}
int main() 
{
    int tot;
    scanf ( "%d\n" , &tot) ; //读入测试用例个数
    for (int i = 0; i < tot; i++) solve();//处理每个测试用例return 0;
}
