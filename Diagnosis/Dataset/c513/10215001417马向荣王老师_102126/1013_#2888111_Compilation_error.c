#include<stdio.h>
#include<string.h>
long long int GCD(long long int a,long long int b)
{
    while(b^=a^=b^=a%=b);
    return a;
}
int main()
{
    unsigned int p=0;
    long long ansA=0;
    long long ansB=0, ansC=1;
    char s[100]={0};
    scanf("%s",s);
    for (p=0;p<strlen(s);p++)//整数
    {
       if (s[p]=='.') break;
       ansA*=3;
       if (s[p]=='1') ansA += 1;
       if (s[p]=='2') ansA -= 1;
    }
    p++;
    for (;p<strlen(s);p++)//分数
    {
        ansB =ansB * 3;
        if (s[p]=='2') ansB -= 1;
        if (s[p]=='1') ansB += 1;  
        ansC*=3;
    }
    if(ansA>0 && ansB<0)
    {
        ansA--;
        ansB=ansC+ansB;
    }
    if(ansA<0 && ansB>0)
    {
        ansA++;
        ansB=ansC-ansB;
    }
    if(ansA==0) 
    {
        ansB=-ansB;
    }
    long long int t=GCD(abs(ansB),abs(ansC));
    if(ansB==0) printf("%lld ",ansA);
    else
    {
        if(ansA!=0) printf("%lld ",ansA);
        printf("%lld %lld",ansB\t,ansC\t);
    }
    return 0;
}