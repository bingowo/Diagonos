#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char s[501]={'\0'};
        scanf("%s",&s);
        int count=1;
        for(int j=0;j<strlen(s);j++)
        {
            if(s[j]!=s[j+1])
            {
                printf("%d%c",count,s[j]);
                count=1;
            }
            else if((s[j]==s[j+1])&&(count<255)) count++;
            if(count==255)
            {
                printf("255%c",s[j]);
                count=1;
            }
        }
        char a=10;
        printf("%c",a);
    }
    return 0;
}
