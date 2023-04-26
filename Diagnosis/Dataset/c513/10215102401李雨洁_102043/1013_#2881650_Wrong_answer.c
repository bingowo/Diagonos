#include <stdio.h>
#include <string.h>
#include <math.h>
int GCD(int m,int n)
{
    return n ? GCD(n,m%n) : m;
}
int main()
{
    char s[1000];
    scanf("%s",s);
    int len = strlen(s);
    unsigned int p = 0;
    long long ansA = 0,ansB = 0,ansC = 1;
    for(;p<len;p++)
    {
        if(s[p]=='.')break;
        ansA *= 3;
        if(s[p]=='1') ansA += 1;
        if(s[p]=='2') ansA -= 1;
    }
   for (p++ ; p<len ; p++)
    {
        ansB =ansB * 3;
        if (s[p]=='2') ansB -= 1;
        if (s[p]=='1') ansB += 1;
        ansC = ansC * 3;
   }
   long long t = GCD(abs(ansB),abs(ansC));
   if (ansB==0) printf("%lld\n",ansA);
    else
    {
        if (ansA!=0) printf("%lld ",ansA);
        printf("%lld %lld\n",ansB/t,ansC/t);
    }
    return 0;
}
