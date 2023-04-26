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
    for(i = 0;i < T;i++)
    {
        char word[30],ch;
        char**text;
        int count = 0,j = 0;
        text = (char**)malloc(100*sizeof(char*));
        while((ch = getchar()) != '\n')
        {
            while(isalnum(ch))
            {
                word[j++] = ch;
                continue;
            }
            word[j] = '\0';
            for(int k = 0;k < count;k++)
            {
                if(strcmp(text[k],word) == 0)
                    break;
                else
                {
                    int len = strlen(word);
                    text[count] = (char*)malloc(len + 1);
                    strcpy(text[count],word);
                    count++;
                }
            }
        }
        qsort(text,count,sizeof(char*),cmp);
        printf("case #%d:\n",i);
        for(j = 0;j < count;j++)
        {
            printf("%s%c",text[j],(j == count - 1)?'\n':' ');
            free(text[j]);
        }
        free(text);
    }
    return 0;
}