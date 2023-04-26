#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define L 1000000007;
int main()
{
    char s[1001];scanf("%s",s);
    int i,j,k;long long sum=1;
    if(strlen(s)==1)sum=1;
    else if(strlen(s)==2)
    {
        if(s[0]==s[1])sum=1;
        else sum=2;
    }
    else
    for(i=0;i<strlen(s);i++)
    {
        if(i==0)
        {
            if(s[0]==s[1])k=1;
            else k=2;
            sum=sum*k%L;
        }
        else if(i==strlen(s)-1)
        {
            if(s[strlen(s)-1]==s[strlen(s)-2])k=1;
            else k=2;
            sum=sum*k%L;
        }
        else
        {
            if(s[i]==s[i-1]&&s[i-1]==s[i+1]&&s[i+1]==s[i])k=1;
            else if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1])k=3;
            else k=2;
            sum=sum*k%L;
        }
    }
    printf("%lld",sum);
}