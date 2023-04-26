#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int cmp(const void*s1,const void*s2)
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
        char word[30],ch;
        char**text;
        int count = 0,j = 0,flag = 1;
        text = (char**)malloc(100*sizeof(char*));
        while((ch = getchar()) != '\n')
        {
            while(isalnum(ch))
            {
                word[j++] = ch;
                ch = getchar();
                continue;
            }
            word[j] = '\0';
            if(strlen(word) == 0)
                continue;
            int len = strlen(word);
            text[count] = (char*)malloc(len + 1);
            strcpy(text[count],word);
            count++;
            j = 0;
        }
        qsort(text,count,sizeof(char*),cmp);
        printf("case #%d:\n",i);
        printf("%s ",text[0]);
        for(j = 1;j < count;j++)
        {
            if(strcmp(text[j],text[j - 1]) == 0)
                continue;
            else
                printf("%s ",text[j]);
        }
        putchar('\n');
    }
}