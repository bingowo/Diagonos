#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int cmp(const void*s1,const void*s2)
{
    return strcmp(*(char**)s1,*(char**)s2);
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        char word[30],temp[30];
        char**text;
        text = (char**)malloc(100*sizeof(char*));
        int count = 0,j,flag = 0;
        while(scanf("%s",word) && !isalnum(word[strlen(word) - 1]))
        {
            for(j = 0;j < count;j++)
            {
                if(strcmp(text[j],word) == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
            {
                flag = 0;
                continue;
            }
            else
            {
                text[count] = (char*)malloc(30);
                strcpy(text[count],word);
                count++;
            }

        }
        qsort(text,count,sizeof(char*),cmp);
        printf("case #%d:\n",i);
        for(j = 0;j < count;j++)
        {
            printf("%s%c",text[j],(j == count-1)?'\n':' ');
            free(text[j]);
        }
        free(text);
    }
}