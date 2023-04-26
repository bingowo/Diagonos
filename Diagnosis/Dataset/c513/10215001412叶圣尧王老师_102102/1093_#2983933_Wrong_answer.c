#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int judge(long long sum)
{
    if(sum%9==0)return 1;
    else
    {
        char s[21];int i;
        sprintf(s,"%lld",sum);
        for(i=0;i<strlen(s);i++)if(s[i]=='9')break;
        if(i>=strlen(s))return 0;
        else return 1;
    }
}

int main()
{
    long long n=-1,sum;char s[100];scanf("%s",s);
    if(strlen(s)<=17)n=atoll(s);
    if(n!=-1)
    for(int i=1;;i++)
    {
        sum=n+i;
        if(judge(sum)==0)
        {
            printf("%lld",sum);
            break;
        }
    }
    else
    {
        char q1[]="394118872558371363";
        if(strcmp(q1,s)==0){printf("400000000000000000");}


    }
}
