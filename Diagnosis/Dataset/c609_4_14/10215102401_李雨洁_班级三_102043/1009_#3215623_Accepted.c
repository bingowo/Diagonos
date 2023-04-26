#include <stdio.h>
#include <string.h>
int gcd(int m, int n)//得到最大公约数
{
    return n ? gcd(n,m%n) : m;
}
int getOne(char c)//得到1的个数
{
    int cnt = 0;
    if(c < 0)
    {
        cnt++;
        c ^= 128;
    }
    while(c)
    {
        if(c%2) cnt++;
        c /= 2;
    }
    return cnt;
}
int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    for(int z = 0; z < n; z++)
    {
        char s[120] = {'\0'},ch;
        //char ch,s[120];
        int i = 0;
        while((ch = getchar()) != '\n') s[i++] = ch;

        int len = strlen(s);
        int A = 0;  //分子
        for(int j = 0; j < len; j++)
        {
            A += getOne(s[j]);
        }
        int B = len * 8; //分母

        int x=gcd(A,B);
        A /= x;
        B /= x;//化简
        printf("%d/%d\n", A, B);
    }
    return 0;
}
