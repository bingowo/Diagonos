#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct data
{
    int a;
    int x;
};
int main()
{
    char s[100];
    scanf("%s",s);
    int sum=0,i,mid[100],flag;
    for(i=2;i<strlen(s);i++)
    {
        if(s[i]>='a') sum=16*sum+s[i]-'a'+10;
        else sum=16*sum+s[i]-'0';
    }
    for(i=0;sum>0;i++)
    {
        mid[i]=sum%10;
        sum/=10;
    }
    flag=i;
    struct data ret;
    ret.a=0,ret.x=mid[flag-1];
    for(i=flag-2;i<=0;i--)
    {
        int t=ret.a;
        ret.a=ret.x-t;
        ret.x=mid[i]-t-ret.x;
    }
    printf("%d%di",ret.x,ret.a);
    return 0;
}


