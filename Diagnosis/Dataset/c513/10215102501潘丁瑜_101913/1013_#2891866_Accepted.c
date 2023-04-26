#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long int gcd(long long int a,long long int b);
int main()
{
    char s[50];
    scanf("%s",s);
    unsigned int p=0;
    long long int ansA = 0;
    long long int ansB = 0,ansC = 1;
    long long int t = 0;
    for(;p<strlen(s);p++)
    {
        if(s[p]=='.') break;
        ansA = ansA *3;
        if (s[p] == '1') ansA +=1;
        if(s[p] == '2') ansA -=1;
    }
    p++;
    for(;p<strlen(s);p++)
    {
        ansB = ansB*3;
        if (s[p]=='1') ansB +=1;
        if(s[p]=='2') ansB -=1;
        ansC = ansC*3;
    }
    t = gcd(abs(ansB),abs(ansC));
    if(ansA > 0 && ansB <0)
    {
        ansA--;
        ansB = ansC + ansB;
    }
    else if(ansA < 0 && ansB >0)
    {
        ansA++;
        ansB = ansC - ansB;
        if(ansA == 0) ansB = -ansB;
    }

    if (ansB==0) printf("%lld\n",ansA);
    else
    {
        if (ansA!=0) printf("%lld ",ansA);
        printf("%lld %lld\n",ansB/t,ansC/t);
    }

    return 0;
}
long long int gcd(long long int a,long long int b)
{
    return a?gcd(b%a,a):b;
}