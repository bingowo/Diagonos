#include <stdio.h>
#include <string.h>

int gcd(int m, int n)
{
    return n ? gcd(n,m%n) : m;
}

int getOne(char c)
{
    int cnt = 0;
    if(c<0)
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
    for(int i = 0; i < n; i++)
    {
        char str[125] = {'\0'};
        char ch;
        int index = 0;
        while((ch = getchar()) != '\n')
        {
            str[index++] = ch;
        }
        int len = strlen(str);
        int A = 0;
        for(int j = 0; j < len; j++)
        {
            A += getOne(str[j]);
        }
        int B = len*8;
        int g = gcd(A, B);
        A /= g;
        B /= g;
        printf("%d/%d\n", A, B);
    }
    return 0;
}