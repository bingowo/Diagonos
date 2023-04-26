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
            char a[17],b[17];
            long long p = 0,q = 0,j,f1=1,f2=1;
            for(j = 0;j<strlen(s);j++)
            {
                if(s[j]=='[') break;
                else a[p++] = s[j];
                f1*=10;
            }
            a[p] = '\0';
            //printf("%s",a);
            for(j = p+1;j<strlen(s);j++)
            {
                if(s[j]==']') break;
                else b[q++] = s[j];
                f2*=10;
            }
            b[q] = '\0';
            //printf("%s",b);
            long long A = atoi(a),B = atoi(b),res1,res2,flag,d;
            if(B!=0)
            {flag = f2-1;
            res1 = A*flag+B;res2 = flag*f1;
            d = gcd(res1,res2);}
            else{res2 = f1;
            res1 = A;
            //printf("%d %d ",p,res2);
            d = gcd(res1,res2);
            }
            res2 /= d;
            res1 = m*res2+res1/d;
            printf("case #%d:\n%lld/%lld\n",i,res1,res2);
    }
}
