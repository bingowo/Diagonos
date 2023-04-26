#include <stdio.h>
#include <string.h>

typedef long long LL;

LL GCD(LL a,LL b)
{
    return !b ? a : GCD(b, a % b);
}

int main()
{
    char s[31];
    scanf("%s",s);
    int p=0;
    LL ansA=0,ansB=0,ansC=1;
    for(;p<strlen(s);p++)
    {
        if(s[p]=='.')break;
        ansA*=3;
        if(s[p]=='1')ansA+=1;
        else if(s[p]=='2')ansA-=1;
    }
    p++;
    for(;p<strlen(s);p++)
    {
        ansB*=3;
        if(s[p]=='1')ansB+=1;
        else if(s[p]=='2')ansB-=1;
        ansC*=3;
    }
    if(ansA>0&&ansB<0)
    {
        ansA--;
        ansB=ansC+ansB;
    }
    else if(ansA<0&&ansB>0)
    {
        ansA++;
        ansB=ansC-ansB;
        if(ansA==0)ansB=-ansB;
    }
    if(ansB==0)printf("%lld\n",ansA);
    else
    {
        LL t=GCD(abs(ansB),abs(ansC));
        if(ansA!=0)printf("%lld ",ansA);
        printf("%lld %lld\n",ansB/t,ansC/t);
    }
    return 0;
}