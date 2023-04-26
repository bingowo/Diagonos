#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int table[256];
int cmp(const void*a,const void*b)
{
    int i = 0;
    char temp1,temp2;
    temp1 = toupper((*(char(*)[21])a)[i]);
    temp2 = toupper((*(char(*)[21])b)[i]);
    while(temp1 == temp2)
    {
        i++;
        temp1 = toupper((*(char(*)[21])a)[i]);
        temp2 = toupper((*(char(*)[21])b)[i]);
    }
    return table[temp1] - table[temp2];
}
int main()
{
    char order[27];
    char ch;
    while(scanf("%s",order) == 1)
    {
        int i;
        for(i = 0;i < 26;i++)
            table[order[i]] = i;
        char s[21];
        char input[100][21];
        for(i = 0;scanf("%s",input[i]) == 1;i++)
        {
            ch = getchar();
            if(ch == '\n')
                break;
        }
        i++;
        qsort(input,i,sizeof(char[21]),cmp);
        for(int j = 0;j < i;j++)
        {
            printf("%s%c",input[j],(j == i-1)?'\n':' ');
        }
    }
    return 0;
}
