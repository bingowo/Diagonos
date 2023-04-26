#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 60

long long gcd(long long m,long long n)
{
    if (n==0) return m;
    else return gcd(n,m%n);
}

long long pwr(int n)
{
    long long result=1;
    for (int i=0;i<n;i++)
    {
        result=result*3;
    }
    return result;
}

long long trans(char* s)
{
    int i;
    long long result=0;
    for (i=0;i<strlen(s);i++)
    {
        if (s[i]=='1') result=result+pwr(strlen(s)-i-1);
        if (s[i]=='0') ;
        if (s[i]=='2') result=result-pwr(strlen(s)-i-1);

    }
    return result;
}


int main()
{
    char s[MAX]={0};
    scanf("%s",s);
    int i,j;
    for (i=0;i<strlen(s) && s[i]!='.' ;i++) ;
    char s1[MAX]={0},s2[MAX]={0};
    strncpy(s1,s,i);
    long long result1=trans(s1);
    if (i==strlen(s))
    {
        printf("%lld\n",result1);
    }
    else
    {
        j=i+1;
        for (j,i=0;j<strlen(s);j++,i++) s2[i]=s[j];
        long long result2=trans(s2);
        long long result3=pwr(i),tmp;
        tmp=result2/gcd(result3,result2);
        if ((tmp<0 && result2>0) || (tmp>0 && result2<0)) result2=-tmp;
        else result2=tmp;
        result3=result3/gcd(result3,result2);
        if (result3<0) result3=-result3;
        if (result1>0)
        {
            if (result2<0)
            {
                result1--;
                result2=result3+result2;
                printf("%lld %lld %lld\n",result1,result2,result3);
            }
            else printf("%lld %lld %lld\n",result1,result2,result3);
        }
        if (result1<0)
        {
             if (result2>0)
            {
                result1++;
                result2=result3-result2;
                printf("%lld %lld %lld\n",result1,result2,result3);
            }
            else printf("%lld %lld %lld\n",result1,-result2,result3);
        }
        if (result1==0) printf("%lld %lld\n",result2,result3);
    }
}
