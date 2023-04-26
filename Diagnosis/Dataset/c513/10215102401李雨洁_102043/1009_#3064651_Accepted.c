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
        int i = 0;
        while((ch = getchar()) != '\n') s[i++] = ch;
        int len = strlen(s),A = 0;  //A为分子
        for(int j = 0; j < len; j++) //得到全部1的个数
        {
            A += getOne(s[j]);
        }
        int B = len * 8; //B为分母
        int g = gcd(A, B); //g为最大公约数
        A /= g; B /= g;
        printf("%d/%d\n", A, B);
    }
    return 0;
}