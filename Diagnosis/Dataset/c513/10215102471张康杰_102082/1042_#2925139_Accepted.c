//第一种方法，不使用递归
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int cmp(const void*s1,const void*s2)
{
    if(*(char*)s1 + 32 == *(char*)s2)
        return -1;
    else if(*(char*)s1 == *(char*)s2 + 32)
        return 1;
    else
        return *(char*)s1 - *(char*)s2;
    
}
int cmp_out(const void*s1,const void*s2)
{
    return strcmp(*(char**)s1,*(char**)s2);
}
int main()
{
    int T,i;
    scanf("%d",&T);
    getchar();
    for(i = 0;i < T;i++)
    {
        int count = 0;
        char ch;
        char s[17];
        int table[256];
        memset(table,1,sizeof(int)*256);
        while((ch = getchar()) != '\n')
        {
            if(table[ch])
            {
                table[ch] = 0;
                s[count++] = ch;
            }
        }
        s[count] = '\0';
        qsort(s,strlen(s),sizeof(char),cmp);
        char**input;
        int len = (int)pow(2,strlen(s)) - 1,j;
        
        input = (char**)malloc(sizeof(char*)*(len));
        
        for(j = 0;j < len;j++)
        {
            int temp = j + 1;
            char comb[17];
            int pos1 = 0,pos2 = 0;
            input[j] = (char*)malloc(17*sizeof(char));
            while(temp != 0)
            {
                if(temp % 2 == 1)
                {
                    comb[pos2] = s[pos1];
                    pos2++;
                }
                temp /= 2;
                pos1++;
            }
            comb[pos2] = '\0';
            strcpy(input[j],comb);
        }
        qsort(input,len,sizeof(char*),cmp_out);
        printf("case #%d:\n",i);
        for(j = 0;j < len;j++)
        {
            printf("%s\n",input[j]);
            free(input[j]);
        }
        free(input);
    }
}