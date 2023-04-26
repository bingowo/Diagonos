#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define L 22

int cmp(const void*a,const void*b)
{
    return *(char*)a - *(char*)b;
}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        char input[22] = {'0'},min;
        scanf("%s",input + 1);
        int j,pos,len = strlen(input);
        for(j = len - 1;j > 0 && input[j] <= input[j - 1];j--);
        pos = j - 1;
        min = input[j];
        for(j;j < len;j++)
        {
            if(input[j] < min)
            {
                min = input[j];
                input[j] = input[pos];
                input[pos] = min;
            }
        }
        qsort(input + pos,len - pos - 1,sizeof(char),cmp);
        printf("case #%d:\n",i);
        if(input[0] == '0')
            printf("%s\n",input + 1);
        else
            printf("%s\n",input);
    }
    return 0;
}