#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char s[101];
    scanf("%s",s);
    int count=0,temp=0;
    int flag=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(isalpha(s[i]))
        {
            if(temp>count)
            {
                count=temp;
            }
            temp=0;
            flag=0;
        }
        else{
            if(s[i]=='0'&&flag==0)
            {
                temp=0;
            }
            else{
                temp++;
                flag=1;
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