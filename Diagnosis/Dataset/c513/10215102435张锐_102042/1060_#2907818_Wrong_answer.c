#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s[200];
    scanf("%s",s);
    int len=strlen(s);
    int num=0,temp=0;
    for(int i=0;i<len;i++)
    {
        if(isdigit(s[i])&&s[i]!='0') temp++;
        if(isdigit(s[i])) ;
        else
        {
            temp=0;
        }
        if(temp>num) num=temp;
    }
    printf("%d",num);
}
