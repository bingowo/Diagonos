#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char s[110];
    scanf("%s",&s);
    int count=0,ans=0,flag=0,i=0;
    while(i<strlen(s))
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            if(s[i]!='0')
            {
                flag=1;
            }
            while(flag==0)
            {
                i++;
                if(s[i]!='0')
                {
                    flag=1;
                }
            }
            count++;
        }
        else
        {
            ans=ans>count?ans:count;
            count=0;
            flag=0;
        }
        i++;
    }
    ans=ans>count?ans:count;
    printf("%d",ans);
    return 0;
}

