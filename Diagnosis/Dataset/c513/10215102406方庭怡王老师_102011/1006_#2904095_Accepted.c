#include<stdio.h>
#include<stdlib.h>

int gcd(long long int m,long long int n)
{
    long long int r;
    while((m%n)!=0)
    {
        r=m%n;
        m=n;
        n=r;
    }

    return n;
}

int main()
{
    int question,i,d,p=0;
    char s[100];
    scanf("%d",&question);
    for(d=0;d<question;d++)
    {
        printf("case #%d:\n",d);
        unsigned int p=0;
        long long ansA=0;
        long long ansB=0, ansC=1;
        scanf("%s",s);
        for (;p<strlen(s);p++)
        {
                if (s[p]=='.') break;
                ansA = ansA *3;
                if (s[p]=='1') ansA += 1;
                if (s[p]=='-') ansA -= 1;
        }
        p++;
        for (;p<strlen(s);p++)
        {
            ansB =ansB * 3;
            if (s[p]=='-') ansB -= 1;
            if (s[p]=='1') ansB += 1;
            ansC = ansC * 3;
        }
        if (ansB==0)
            printf("%lld\n",ansA);
        else
        {
            long long t=gcd(abs(ansC),abs(ansB));
            if (ansA!=0)
                printf("%lld ",ansA);
            printf("%lld %lld\n",ansB/t,ansC/t);
        }
    }
    return 0;
}