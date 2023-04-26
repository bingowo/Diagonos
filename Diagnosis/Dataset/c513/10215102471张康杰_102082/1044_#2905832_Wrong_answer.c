#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char input[100001];
    int table[128];
    memset(table,-1,sizeof(int)*128);
    table['0'] = 0,table['1'] = 1,table['2'] = 2,table['3'] = 3,table['4'] = 4;
    table['5'] = 5,table['6'] = 6,table['7'] = 7,table['8'] = 8,table['9'] = 9;
    table['a'] = 10,table['b'] = 11,table['c'] = 12,table['d'] = 13,table['e'] = 14;
    table['f'] = 15;
    scanf("%s",input);
    char*pt = strstr(input,"0x");
    if(pt == NULL)
        printf("-1");
    else
    {
        while(pt != NULL)
        {
            unsigned int num = 0;
            pt += 2;
            if(table[*pt] == -1)
            {
                pt = strstr(pt,"0x");
                continue;
            }
            while(table[*pt] != -1)
            {
                num = num*16 + table[*pt];
                pt++;
            }
            printf("%u ",num);
            pt = strstr(pt,"0x");
        }
    }
    //if((pt = strstr(pt,"0x")) == NULL)
        //printf("-1");
}