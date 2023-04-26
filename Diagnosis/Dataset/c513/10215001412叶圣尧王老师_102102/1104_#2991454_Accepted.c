#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char s1[5],s2[100];int a[26]={0};
    while(scanf("%s %s",s1,s2)!=EOF)
    {
        if(strcmp(s1,"IN")==0)
            a[s2[0]-65]=atoi(s2+3);
        else if(strcmp(s1,"OUT")==0)
            printf("%d\n",a[s2[0]-65]);
        else if(strcmp(s1,"MOV")==0)
            a[s2[0]-65]=a[s2[3]-65];
        else if(strcmp(s1,"XCHG")==0)
        {int t=a[s2[0]-65];a[s2[0]-65]=a[s2[3]-65];a[s2[3]-65]=t;}
        else if(strcmp(s1,"ADD")==0)
        {
            if(strlen(s2)==5)a[s2[0]-65]+=a[s2[3]-65];
            else a[s2[0]-65]=a[s2[3]-65]+a[s2[6]-65];
        }
        else if(strcmp(s1,"SUB")==0)
        {
            if(strlen(s2)==5)a[s2[0]-65]-=a[s2[3]-65];
            else a[s2[0]-65]=a[s2[3]-65]-a[s2[6]-65];
        }
        else if(strcmp(s1,"MUL")==0)
        {
            if(strlen(s2)==5)a[s2[0]-65]*=a[s2[3]-65];
            else a[s2[0]-65]=a[s2[3]-65]*a[s2[6]-65];
        }
        else if(strcmp(s1,"DIV")==0)
        {
            if(strlen(s2)==5)a[s2[0]-65]/=a[s2[3]-65];
            else a[s2[0]-65]=a[s2[3]-65]/a[s2[6]-65];
        }
        else if(strcmp(s1,"MOD")==0)
        {
            if(strlen(s2)==5)a[s2[0]-65]%=a[s2[3]-65];
            else a[s2[0]-65]=a[s2[3]-65]%a[s2[6]-65];
        }
        else if(strcmp(s1,"AND")==0)
        {
            if(strlen(s2)==5)a[s2[0]-65]&=a[s2[3]-65];
            else a[s2[0]-65]=a[s2[3]-65]&a[s2[6]-65];
        }
        else if(strcmp(s1,"OR")==0)
        {
            if(strlen(s2)==5)a[s2[0]-65]|=a[s2[3]-65];
            else a[s2[0]-65]=a[s2[3]-65]|a[s2[6]-65];
        }
        else if(strcmp(s1,"XOR")==0)
        {
            if(strlen(s2)==5)a[s2[0]-65]^=a[s2[3]-65];
            else a[s2[0]-65]=a[s2[3]-65]^a[s2[6]-65];
        }
    }
}