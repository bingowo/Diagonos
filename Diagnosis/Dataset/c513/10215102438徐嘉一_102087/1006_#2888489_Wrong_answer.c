#include <stdio.h>
#include <stdlib.h>

long long int GCD(unsigned int e,unsigned int b)
{
    if(b)
        return GCD(b,e%b);
    else
        return e;
}
int main()
{
    int T;char s[30];unsigned int p=0;
    long long ansA=0;
    long long ansB=0,ansC=1;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        gets(s);
        for(;p<strlen(s);p++)
        {
            if(s[p]=='1') ansA+=1;
            if(s[p]=='2') ansA-=1;
        }
        p++;
        for(;p<strlen(s);p++)
        {
            ansB=ansB*3;
            if(s[p]=='2') ansB-=1;
            if(s[p]=='1') ansB+=1;
            ansC=ansC*3;
        }
        if(ansA>0 && ansB<0)
            ansA--;ansB=ansC+ansB;
        if(ansA<0 && ansB>0)
            ansA++;ansB=ansC-ansB;
        if(ansA==0) ansB=-ansB;
        long long t=GCD(abs(ansB),abs(ansC));
        if(ansB==0) printf("%lld\n",ansA);
        else
        {
            if(ansA!=0) printf("%lld",ansA);
            printf("%lld%lld\n",ansB/t,ansC/t);
        }
    }
    return 0;
}
