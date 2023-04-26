#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*s1,const void*s2)
{
    return *(int*)s2 - *(int*)s1;
}
int main()
{
    char input[1000000];
    scanf("%s",input); 
    int table[256],len = strlen(input),i,count = 0;
    int longest_cur = 0,longest_max = 0;
    memset(table,-1,sizeof(int)*256);
    for(i = len - 1;i >= 0;i--)
    {
        if(table[input[i]] == -1)
        {
            longest_cur++;
            table[input[i]] = i; 
        }
        else
        {
            if(longest_cur >= longest_max)
            {
                longest_max = longest_cur;
            }
            longest_cur = 1;
            memset(table,-1,sizeof(int)*256);
            table[input[i]] = i;
        }

    }
    if(longest_cur >= longest_max)
    {
        longest_max = longest_cur;
    }
    qsort(table,256,sizeof(int),cmp);
    for(i = longest_max - 1;i >=0;i--)
    {
        putchar(input[i]);
    }

}