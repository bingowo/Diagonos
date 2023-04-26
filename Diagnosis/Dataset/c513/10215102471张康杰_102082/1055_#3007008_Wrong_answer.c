#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define L 1000001

int main()
{
    char input[L];
    scanf("%s",input);
    int i,j,len = strlen(input);
    int pos = 0,pos1,len_cur = 0,len_max = 0,final_pos;
    int table[128];
    memset(table,-1,sizeof(int) * 128);
    for(i = 0;i < len;i++)
    {
        if(table[input[i]] == -1 || table[input[i]] < pos)
        {
            table[input[i]] = i;
            len_cur++;
        }
        else
        {
            if(len_cur > len_max)
            {
                len_max = len_cur;
                final_pos = pos;
            }
            pos = table[input[i]] + 1;
            table[input[i]] = i;
            pos1 = i + 1;
            len_cur = pos1 - pos;
            i = pos1;
        }
    }
    if(len_cur > len_max)
    {
        len_max = len_cur;
        final_pos = pos;
    }
    for(i = final_pos;i < final_pos + len_max + 1;i++)
        putchar(input[i]);
    putchar('\n');
    return 0;
}