#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    return (*(int*)a-*(int*)b);
}
int main()
{
    char s[101]={'\0'};
    scanf("%s",&s);
    int longest=0;
    int tmpt=0;
    for(int i=0;i<strlen(s);i++)
    {
        if((s[i]>='1')&&(s[i]<='9'))
        {
            while((s[i]>='0')&&(s[i]<='9'))
            {
                tmpt++;
                i++;
            }
            if(tmpt>longest) longest=tmpt;
        }
    }
    printf("%d",longest);

    return 0;
}
