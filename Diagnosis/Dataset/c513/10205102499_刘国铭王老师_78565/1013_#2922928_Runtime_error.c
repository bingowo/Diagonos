#include <stdio.h>
#include <stdlib.h>

long long gcd(long long a,long long b)
{
    long long max=(a>b) ? a:b;
    long long min=(a<b) ? a:b;
    while(max%min)
    {
        long long temp=max%min;
        max=min;
        min=temp;
    }
    return min;
}

int main()
{
    char s[31];
    scanf("%s",&s);
    int num=strlen(s);
    long long ansA=0,ansB=0,ansC=1;
    unsigned int p=0;
    for(;p<num;p++)
    {
        if(s[p]=='.') break;
        ansA=ansA*3;
        if(s[p]=='1') ansA+=1;
        if(s[p]=='2') ansA-=1;
    }
    p++;
    for(;p<num;p++)
    {
        ansB=ansB*3;
        if(s[p]=='1') ansB+=1;
        if(s[p]=='2') ansB-=1;
        ansC=ansC*3;
    }
    long long t=gcd(ansB,ansC);
    if(ansB==0)
        printf("%lld",ansA);
    else
    {
        if(ansA!=0)
        {
            if(ansB<0)
                ansB=ansC+ansB;
            printf("%lld %lld %lld",ansA,ansB/t,ansC/t);
        }
        if(ansA==0)
        {
            if(ansB<0)
                ansB=ansC+ansB;
            printf("%lld %lld",ansB/t,ansC/t);
        }
    }
    return 0;

}
