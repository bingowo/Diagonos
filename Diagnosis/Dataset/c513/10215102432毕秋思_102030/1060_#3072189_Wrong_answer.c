#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char s[110];
    scanf("%s",&s);
    int count=0,ans=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            count++;
        }
        else
        {
            ans=ans>count?ans:count;
            count=0;
        }
    }
    ans=ans>count?ans:count;
    printf("%d",ans);
    return 0;
}

