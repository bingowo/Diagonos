#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortt(char* s,char c,int l)
{
    int i;
    if(c>=s[0])
    {
        for(i=l;i>0;i--)
            s[i]=s[i-1];
        s[0]=c;
    }
    else
        s[l]=c;
}

int main()
{
    char s1[10001]={0},s2[10001]={0},s3[10001]={0};
    scanf("%s",s1);
    int i,len=strlen(s1);
    for(i=0;s1[i];i++)
    {
        if(s1[i]>=91)
            s2[i]=s1[i]-32;
        else
            s2[i]=s1[i];
    }
    s3[0]=s2[0];
    for(i=1;i<len;i++)
    {
        char c=s2[i];
        int l=strlen(s3);
        sortt(s3,c,l);
    }
    printf("%s",s3);
}