#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int gcd(int x, int y)
{	if (y)
        return gcd(y, x%y);
    else
        return x;
}

int main()
{
    char s[50];
    scanf("%s",s);
    unsigned int p=0;
    long long ansA=0;
    long long ansB=0, ansC=1;
    for (;p<strlen(s);p++) {
        if (s[p]=='.') break;
        ansA = ansA *3;
        if (s[p]=='1') ansA += 1;
        if (s[p]=='2') ansA -= 1;
    }
    p++;
    for (;p<strlen(s);p++) { 
        ansB = ansB * 3;      
        if (s[p] == '2') ansB -= 1;
        if (s[p] == '1') ansB += 1;
        ansC = ansC * 3;
    }
    long long t=gcd(llabs(ansB),llabs(ansC));
    if (ansB==0) printf("%lld\n",ansA);
    else
    {   if (ansA!=0) printf("%lld ",ansA);
        printf("%lld %lld\n",ansB/t,ansC/t);
    }
    return 0;
}
