#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b)
    {return a ? gcd(b % a, a) : b;}


int main()
{
    unsigned int p=0;
    long long ansA=0;
    long long ansB=0,ansC=1;

    char s[100];
    scanf("%s",&s);

    //整数
    for(;p<strlen(s);p++){
        if(s[p]=='.') break;
        ansA=ansA*3;
        if (s[p]=='1') ansA += 1;
        if (s[p]=='2') ansA -= 1;
    }
    p++;

    //小数
    for (;p<strlen(s);p++) {
        ansB =ansB * 3;
        if (s[p]=='2') ansB -= 1;
        if (s[p]=='1') ansB += 1;
        ansC = ansC * 3;
    }

    if(ansA>0&&ansB<0)
    {
        ansA--;
        ansB=ansC+ansB;
    }
    if(ansA<0&&ansB>0)
    {
        ansA++;
        ansB=ansC-ansB;
        if(ansA==0) ansB=-ansB;
    }
    

    //辗转相除
    long long t=gcd(abs(ansB),abs(ansC));


    if (ansB==0) printf("%lld\n",ansA);
    else
    {if (ansA!=0) printf("%lld ",ansA);
        printf("%lld %lld\n",ansB/t,ansC/t);
    }
    return 0;
}
