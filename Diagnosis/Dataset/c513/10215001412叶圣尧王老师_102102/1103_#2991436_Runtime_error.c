#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char s1[5],s2[10];int a[4]={0};
    while(scanf("%s",s1)!=EOF)
    {
        scanf("%s",s2);
        if(strcmp(s1,"IN")==0)
            a[s2[0]-65]=atoi(s2+3);
        else if(strcmp(s1,"MOV")==0)
            a[s2[0]-65]=a[s2[3]-65];
        else if(strcmp(s1,"ADD")==0)
            a[s2[0]-65]+=a[s2[3]-65];
        else if(strcmp(s1,"SUB")==0)
            a[s2[0]-65]-=a[s2[3]-65];
        else if(strcmp(s1,"MUL")==0)
            a[s2[0]-65]*=a[s2[3]-65];
        else if(strcmp(s1,"DIV")==0)
            a[s2[0]-65]/=a[s2[3]-65];
        else if(strcmp(s1,"OUT")==0)
            printf("%d\n",a[s2[0]-65]);
    }
}
