#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long long gcd(long long a,long long b)
{
    return a?gcd(b%a,a):b;
}

int main()
{
    char s[100000];
    unsigned int p=0;
    long long ansA=0;
    long long ansB=0,ansC=1;
    scanf("%s",s);
    for(;p<strlen(s);p++)
    {
        if(s[p]=='.')break;
        ansA*=3;
        if(s[p]=='1')ansA+=1;
        if(s[p]=='2')ansA-=1;
    }
    p++;
    for(;p<strlen(s);p++)
    {
        ansB*=3;
        if(s[p]=='1')ansB+=1;
        if(s[p]=='2')ansB-=1;
        ansC/=3;
    }
    if(ansA>0&&ansB<0)
    {
        ansA--;
        ansB+=ansC;
    }
    if(ansA<0&&ansB>0)
    {
        ansA++;
        ansB=ansC-ansB;
        if(ansA==0)ansB=-ansB;
    }
    long long t=gcd(abs(ansB),abs(ansC));
    if(ansB==0)printf("%lld\n",ansA);
    else
    {
        if(ansA!=0)printf("%lld ",ansA);
        printf("%lld %lld\n",ansB/t,ansC/t);
    }
    return 0;
}