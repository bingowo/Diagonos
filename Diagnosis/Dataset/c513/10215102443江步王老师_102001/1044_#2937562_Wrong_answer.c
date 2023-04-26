#include<stdio.h>

int main()
{
    char ch;
    char prev=0;
    int flag=0;
    int p=0;
    int t;
    while ((ch=getchar()) != EOF)
    {
        if (!flag)
        {
            if (ch == 'x')
            {
                if (prev == '0')//检测到"0x",开始输入十六进制数
                {
                    flag=1;
                    t=0;
                    continue;
                } 
            }
            prev=ch;
        }
        else if (flag)
        {
            p=1;
            if (ch >= 'a' && ch <= 'f')
            {
                t=t*16+ch-'a'+10;
                continue;
            }
            else if (ch >= '0' && ch <= '9')
            {
                t=t*16+ch-'0';
                continue;
            }
            else
            {
                printf("%d ",t);
                flag=0;
            }
        }
    }
    if (!p)
    {
        printf("-1");
    }
    return 0;
}