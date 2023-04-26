#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char s[1001],ret[2002];
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
        {
            if(s[i]>='a')s[i]=s[i]-32;
        }
    char*l=ret+1000,*r=ret+1000;
    *l=s[0];
    for(int i=1;i<strlen(s);i++)
    {
        if(s[i]>=*l)
        {
            l--;
            *l=s[i];
        }
        else
        {
            r++;
            *r=s[i];
        }
    }
    while(l<=r)
    {
        printf("%c",*l);
        l++;
    }
    return 0;
}
