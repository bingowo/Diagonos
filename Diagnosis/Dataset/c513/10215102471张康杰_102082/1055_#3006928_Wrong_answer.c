#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 1000001

int main()
{
    char input[L];
    scanf("%s",input);
    int i,j,len;
    len = strlen(input);
    int len_max = 0,len_cur = 0,pos;
    for(i = 0;i < len;i++)
    {
        int table[128] = {0};
        for(j = i;j < len;j++)
        {
            if(table[j] == 0)
            {
                table[j] = 1;
                len_cur++;
            }
            else
                break;
        }
        if(len_cur > len_max)
        {
            len_max = len_cur;
            pos = i;
        }
        len_cur = 0;
    }
    for(i = pos;i < pos + len_max;i++)
        putchar(input[i]);
    putchar('\n');
    return 0;
}