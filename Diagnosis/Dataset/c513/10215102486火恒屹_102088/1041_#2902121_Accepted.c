#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[51]={'\0'};
    scanf("%s",&s);
    int length=1;
    int count=1;
    for(int i=0;i<strlen(s);i++)
    {
        if((s[i]!=s[i+1])&&(s[i+1]!=0))
            {
                while((s[i]!=s[i+1])&&(s[i+1]!=0))
                {
                    count++;
                    i++;
                }
                if(count>length)
                    length=count;
                count=1;
            }
    }
    printf("%d",length);
    return 0;
}
