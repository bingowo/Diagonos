#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
//#include "myh.h"
long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char s[20]="",*p=s;
        scanf("%s",s);
        long long a,b=10,c,z=atoll(s);
        int j;
        for(j=0;s[j]!='.'&&s[j];j++);
        if(s[strlen(s)-1]==']')
        {
            int t=0;
            for(;s[j+t+1]!='[';t++){z*=10;z+=s[j+t+1]-'0';};
            a=atoll(p+j+t+2);
            while(b<a)b*=10;
            b--;
            c=gcd(b,a);
            a/=c;b/=c;
            a+=b*z;
            for(int d=0;d<t;d++)b*=10;
            c=gcd(b,a);
            a/=c;b/=c;
        }
        else
        {
            a=atoll(p+j+1);
            b=1;
            for(;s[j+1];j++)b*=10;
            c=gcd(b,a);
            a/=c;b/=c;
            a+=b*z;
        }

        printf("case #%d:\n%lld/%lld\n",i,a,b);
    }

}
