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
            //if(count == 0)
            //{
                //int len = strlen(word);
                //text[count] = (char*)malloc(len + 1);
                //strcpy(text[count],word);
                //count++;
            //}
            for(int k = 0;k < count;k++)
            {
                if(strcmp(text[k],word) == 0)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
            {
                int len = strlen(word);
                text[count] = (char*)malloc(len + 1);
                strcpy(text[count],word);
                count++;
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