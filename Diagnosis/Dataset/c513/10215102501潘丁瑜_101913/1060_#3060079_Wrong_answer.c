#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char str[101]="\0";
    int i;
    scanf("%s",str);
    int max=0,num=0;
    for(i=0;i<strlen(str);i++)
    {
        while(isalpha(str[i])) i++;
        if(i==100) num=0;
        else
        {
            while(isdigit(str[i]))
            {
                if(str[i] != '0')
                    num++;
                i++;
            }
        }
        if(num>max) max=num;
        num=0;
    }
    printf("%d",max);
    return 0;
}