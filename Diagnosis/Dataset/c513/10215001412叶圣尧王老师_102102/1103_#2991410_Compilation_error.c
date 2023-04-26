#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char s1[5],s2[10];int a[4]={0};
    while(scanf("%s %s",s1,s2)!=EOF)
    {
        if(strcmp(s1,"IN")==0)
            a[s2[0]-65]=atoi(s2+3);
        if(strcmp(s1,"MOV")==0)
            a[s2[0]-65]=a[s2[3]-65];
        if(strcmp(s1,"ADD")==0)
            a[s2[0]-65]+=a[s2[3]-65];
        if(strcmp(s1,"SUB")==0)
            a[s2[0]-65]-=a[s[3]-65];
        if(strcmp(s1,"MUL")==0)
            a[s2[0]-65]*=a[s[3]-65];
        if(strcmp(s1,"DIV")==0)
            a[s2[0]-65]/=a[s2[3]-65];
        if(strcmp(s1,"OUT")==0)
            printf("%d",a[s[0]-65]);
    }
}