#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
char s[10000][10000];
int main()
{
    int i=0;int flag=0;
    while(gets(s[i])) i++;
    for(int j=0;j<i;j++)
    {
        for(int k=0;k<strlen(s[j]);k++)
        {
            if((s[j][k]=='/') && (s[j][k+1]=='/'))
            {
                if(k==0)
                {
                     s[j][k]='\0';break;
                }
                else if(k>0 && s[j][k-1]!='"')
                {
                     s[j][k]='\0';break;
                }
            }
        }
    }
    for(int j=0;j<i;j++)
    {
        for(int k=0;k<strlen(s[j]);k++)
        {
            if(s[j][k]=='/' && s[j][k+1]=='*')
            {
                if(k==0)
                {
                    flag=1;break;
                }
                else if(k>0 && s[j][k-1]!='"')
                {
                    flag=1;break;
                }
            }
            else if(s[j][k]=='*' && s[j][k+1]=='/')
            {
                if(k==0)
                {
                    flag=0;k=k+2;
                }
                else if(k>0 && s[j][k-1]!='"')
                {
                    flag=0;k=k+2;
                }
            }
            if(flag==1) continue;
            printf("%c",s[j][k]);
        }
        if(flag==0) printf("\n");
    }
    return 0;
}
