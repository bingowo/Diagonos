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
        if(s[i]>='A') sum=16*sum+s[i]-'A'+10;
        else sum=16*sum+s[i]-'0';
    }
    for(i=0;sum>0;i++)
    {
        mid[i]=sum%2;
        sum/=2;
    }
    flag=i;
    struct data ret;
    ret.a=mid[flag-1],ret.x=0;
    for(i=flag-2;i>=0;i--)
    {
        int t=ret.a;
        ret.a=mid[i]-ret.a-ret.x;
        ret.x=t-ret.x;
    }
    if(ret.a==0) printf("%di",ret.x);
    else if(ret.x==0) printf("%d",ret.a);
    else if(ret.x==1) printf("%d+1",ret.a);
    else if(ret.x>0)  printf("%d+%di",ret.a,ret.x);
    else printf("%d%di",ret.a,ret.x);
    return 0;
}


