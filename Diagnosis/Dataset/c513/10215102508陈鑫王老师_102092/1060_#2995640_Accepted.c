#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char s[101];
    scanf("%s",s);
    int len=0,maxlen=0;
    for(int i=0;i<strlen(s);i++)
    {
        for(;isdigit(s[i])&&s[i]=='0';i++);
        while(isdigit(s[i])&&i<strlen(s))
        {
            len++;
            i++;
        }
        maxlen=maxlen>len?maxlen:len;
        len=0;
    }
    printf("%d",maxlen);
    return 0;
}