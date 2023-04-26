#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void zhuandaxie(char *s)
{
    int len=strlen(s),i;
    for(i=0;i<len;i++)
    {
        if((s[i]<='z')&&(s[i]>='a')) s[i]=s[i]-'a'+'A';
    }

}

void addqian(char*s,char sign)
{
    int len=strlen(s),i;
    s[len+1]=0;
    for(i=len;i>0;i--)
    {
        s[i]=s[i-1];
    }
    s[0]=sign;
}

void addhou(char*s,char sign)
{
    int len=strlen(s);
    s[len]=sign;
    s[len+1]=0;

}

int main()
{
    char s[1100];
    char re[1100];
    scanf("%s",s);
    zhuandaxie(s);
    memset(re,0,sizeof(char)*1100);
    int len=strlen(s),i;
    re[0]=s[0];
    for(i=1;i<len;i++)
    {
        if(s[i]>=re[0]) addqian(re,s[i]);
        else addhou(re,s[i]);
    }
    //printf("s=%s\n",s);
    printf("%s\n",re);
    return 0;
}
