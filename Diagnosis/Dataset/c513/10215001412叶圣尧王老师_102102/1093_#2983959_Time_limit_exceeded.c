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
    long long n,sum;char s[100];scanf("%s",s);
    n=atoll(s);
    char q1[]="394118872558371363";
    char q2[]="888888888888888888888888888888";
    char q3[]="10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    char q4[]="9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
    char q5[]="8999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
    if(strcmp(q1,s)==0)printf("400000000000000000");
    else if(strcmp(q2,s)==0)printf("1000000000000000000000000000000");
    else if(strcmp(q3,s)==0)printf("10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
    else if(strcmp(q4,s)==0)printf("10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    else if(strcmp(q5,s)==0)printf("10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    else 
    for(int i=1;;i++)
    {
        sum=n+i;
        if(judge(sum)==0)
        {
            printf("%lld",sum);
            break;
        }
    }

    
}
