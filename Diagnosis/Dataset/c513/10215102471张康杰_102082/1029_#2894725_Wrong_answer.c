#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int cmp(const void*a,const void*b)
{
    return *(char*)a - *(char*)b;
}
int main()
{
    int T,i;
    scanf("%d",&T);
    getchar();
    for(i = 0;i < T;i++)
    {
        int len,count = 0;
        char input[201];
        char alphabet[201];
        gets(input);
        len = strlen(input);
        int table[len];
        for(int j = 0;j < len;j++)
        {
            if(isalpha(input[j]))
            {
                table[j] = -1;
                alphabet[count] = input[j];
                count++;
            }
            else
            {
                table[j] = j;
            }
        }
        qsort(alphabet,count,sizeof(char),cmp);
        for(int j = 0,k = 0;j < len;j++)
        {
            if(table[j] == -1)
            {
                putchar(alphabet[k]);
                k++;
            }
            else
            {
                putchar(input[j]);
            }

        }
        putchar('\n');

    }
    return 0;
}