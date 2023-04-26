#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    int T, i, temp1, temp2, num, Max=1;
    unsigned int n[10]={0};
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        scanf("%u", &n[i]);
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
                Max = (Max>num)?Max:num;
            }
            else
            {
                Max = (Max>num)?Max:num;
                num = 1;
            }
            n[i] = n[i] >> 1;
            
        }
        printf("case #%d:\n", i);
        printf("%d\n", Max);
    }

    return 0;
}