#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
    char s[51];int lenth,i,n,max;
    scanf("%s",s);
    lenth=strlen(s);max=1;n=1;
    for(i=1;i<lenth;i++)
    {
        if(s[i]!=s[i-1])
        {n++;max=n>max?n:max;}
        else
        n=1;
    }
    printf("%d",max);
}