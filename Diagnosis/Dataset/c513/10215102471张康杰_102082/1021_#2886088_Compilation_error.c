#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*a,const void*b)
{
    return table[**(char**)a] - table[**(char**)b];
}
int main()
{
    char order[27];
    while(scanf("%s",order) != EOF)
    {
        int i;
        char table[256];
        for(i = 0;i < 26;i++)
            table[order[i]] = i;
        char*input[100];
        for(i = 0;scanf("%s",input[i]);i++);
        qsort(input,i,sizeof(char*),cmp);
        for(int j = 0;j < i;j++)
            printf("%s%c",input[j],(j == i-1)?'\n':' ');
    }
    return 0;
}
