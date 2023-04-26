#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int x,k,l,i;
    char s[107];
    scanf("%s",s);
    l = 1;
    x = 0;
    int len = strlen(s);
    for(i = 0,k = 0; i < len; i++)
    {
        if(isdigit(s[i]))
        {
            if(s[i] == '0' && l)
            {
                if(x < k)x = k;
                k = 0;
                continue;
            }
            l = 0;
            k++;
        }
        else
        {
            if(x < k)x = k;
            k = 0;
            l = 1;//下一次进行数串长度计算时，也需要将l重新换为1去掉前导0；
            continue;
        }
    }
    if(x < k)x = k;//注意若全部都是数字，没有这一行的情况下x的值为0；
    printf("%d",x);
    return 0;
}