#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    int a, i, temp1, temp2, num, Max=1;
    unsigned long n[10]={0};
    scanf("%d", &a);
    for (i = 0; i < a; i++)
    {
        scanf("%lu", &n[i]);
    }
    for (i = 0; i < a; i++)
    {
        Max = 1;
        num = 1;
        temp1 = n[i] & 1;
        n[i] = n[i] >> 1;
        while (n[i] != 0)
        {
            temp2 = n[i] & 1;     
            if (temp1 != temp2)
            {
                num++;
                temp1 = temp2;
                Max = Max>num:Max,num;
            }
            else
            {
                Max = Max>num:Max,num;
                num = 1;
            }
            n[i] = n[i] >> 1;
            
        }
        printf("case #%d\n", i);
        printf("%d\n", Max);
    }

    return 0;
}