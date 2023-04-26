#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1010

int main()
{
    char c[MAX], s[MAX];
    while(gets(c))
    {
        memset(s, 0, sizeof(s));
        int len = strlen(c);
        int snt = 0;
        for(int i = 0; i < len; i++)
        {
            if(c[i] != '#')
            {
                if((c[i] >= '0' && c[i] <= '9') || (c[i] >= 'a' && c[i] <= 'f') || (c[i] >= 'A' && c[i] <= 'F'))
                {
                    s[snt++] = c[i];
                }
            }
            else
            {
                int temp = 0;
                int x;
                int p = 1;
                //从后往前转换为十进制的关键代码
                for(int i = snt - 1; i >= 0; i--)
                {
                    if(s[i] >= '0' && s[i] <= '9')
                    {
                        x = s[i] - '0';
                    }
                    else if(s[i] >= 'a' && s[i] <= 'z')
                    {
                        x = s[i] - 'a' + 10;
                    }
                    else if(s[i] >= 'A' && s[i] <= 'Z')
                    {
                        x = s[i] - 'A' + 10;
                    }

                    temp += x * p;
                    p *= 16;
                }
                if(snt > 0)
                {
                    printf("%d\n", temp);
                }
                memset(s, 0, sizeof(s));
                snt = 0;
            }
        }
    }
    return 0;
}