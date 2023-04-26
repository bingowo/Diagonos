#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char s[101];
    scanf("%s",s);
    int count=0,temp=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(isalpha(s[i]))
        {
            if(temp>count)
            {
                count=temp;
            }
            temp=0;
        }
        else{
            if(i==0&&s[i]==0)
            {
                continue;
            }
            if(s[i]==0&&(isalpha(s[i-1])||s[i-1]==0))
            {
                continue;
            }
            else{
                temp++;
            }
        }
    }
    if(temp>count)
    {
        count=temp;
    }
    printf("%d\n",count);
    return 0;
}