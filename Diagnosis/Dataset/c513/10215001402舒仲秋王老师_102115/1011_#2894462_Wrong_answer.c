#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct data
{
    long int a;
    long int x;
};
int main()
{
    char s[100];
    scanf("%s",s);
    long int sum=0,i,mid[100],flag;
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
    if(ret.a==0&&ret.x==0) printf("0");
    else if(ret.a==0) printf("%ldi",ret.x);
    else if(ret.x==0) printf("%ld",ret.a);
    else if(ret.x==1) printf("%ld+i",ret.a);
    else if(ret.x>0)  printf("%ld+%ldi",ret.a,ret.x);
    else printf("%ld%ldi",ret.a,ret.x);
    return 0;
}


