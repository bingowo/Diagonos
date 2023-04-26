#include <stdio.h>
#include <string.h>
#include <math.h>
long long gcd(long long a,long long b)
{
    if(a==0) return b;
    else
    {long long int m;
    m = b%a;
    return gcd(m,a);}
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        char s[17];long long m;
        scanf("%lld.%s",&m,s);
            long long j,k,f1=1,f2=1,A = 0LL,B = 0LL;
            for(j = 0;j<strlen(s);j++)
            {
                if(s[j]=='[') break;
                else A = A*10+s[j]-'0';
                f1*=10;
            }
            for(k = j+1;k<strlen(s);k++)
            {
                if(s[k]==']') break;
                else B = B*10 + s[k]-'0';
                f2*=10;
            }
            long long res1,res2,flag,d;
            if(B!=0)
            {flag = f2-1;
            res1 = A*flag+B;res2 = flag*f1;
            d = gcd(res1,res2);}
            else{res2 = f1;
            res1 = A;
            d = gcd(res1,res2);
            }
            res2 /= d;
            res1 = m*res2+res1/d;
            printf("case #%d:\n%lld/%lld\n",i,res1,res2);
    }
}
