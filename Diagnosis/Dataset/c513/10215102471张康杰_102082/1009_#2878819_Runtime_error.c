#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int GCD(int x, int y)
{
    int temp;
    if(x < y)
    {
        temp = x;
        x = y;
        y = temp;
    }
    if(x % y == 0)
        return y;
    else
        GCD(y,x%y);
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i = 0;i < n;i++)
    {
        int m = 0,j;
        char input[121];
        gets(input);//出错原因：由于scanf不能读取空格，在输入空格时scanf只会读取空格前的字符串，需要

        char*pt = input;
        while(*pt)
        {
            for(j = 0;j < 8;j++)
            {
                if((*pt & 1<<j) != 0)
                    m++;
            }
            pt++;
        }
        printf("%d/%d\n",m/GCD(m,strlen(input)*8),strlen(input)*8/GCD(m,strlen(input)*8));
    }
    return 0;
}

