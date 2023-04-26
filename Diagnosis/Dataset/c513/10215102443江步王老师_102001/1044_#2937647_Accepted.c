#include<stdio.h>

int main()
{
    char ch;
    char prev=0;
    int flag=0;
    int n;
    int p=0;
    long long t;
    ch=getchar();prev=ch;
    while ((ch=getchar()) != EOF)
    {
        if (!flag)
        {
            if (ch == 'x')
            {
                if (prev == '0')//检测到"0x",开始输入十六进制数
                {
                    flag=1;
                    n=0;
                    t=0;
                    continue;
                } 
            }
            prev=ch;
        }
        else if (flag)
        {
            if (ch >= 'a' && ch <= 'f')
            {
                n++;
                t=t*16+ch-'a'+10;
                continue;
            }
            else if (ch >= '0' && ch <= '9')
            {
                n++;
                t=t*16+ch-'0';
                continue;
            }
            else
            {
                if (n != 0)
                {
                    printf("%lld ",t);
                    p=1;
                }
                flag=0;
                prev=ch;
            }
        }
    }
    if (!p)
    {
        printf("-1");
    }
    return 0;
}