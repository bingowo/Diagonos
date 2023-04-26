#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 31
long long int GCD(long long int m,long long int n)
{
    if(m%n==0)return n;
    else if(n%m==0)return m;
    else if(m>n)
    {
        m=m-n;
        return G(m,n);
    }
    else if(m<=n)
    {
        n=n-m;
        return G(m,n);
    }
}

int main()
{
    long long int A=0,B=0,C=1,D;
    int i,d,t;
    char s[N];
    scanf("%s",s);
    for(i=0;s[i]!='.'&&i<strlen(s);i++)
    {
        if(s[i]=='2')d=-1;
        else d=s[i]-'0';
        A=A*3+d;
    }
    for(i+=1;i<strlen(s);i++)
    {
        if(s[i]=='2')d=-1;
        else d=s[i]-'0';
        B=B*3+d;
        C=C*3;
    }
    if(B<0)D=-B;
    else D=B;
    t=GCD(D,C);
    B=B/t;
    C=C/t;
  if(B==0)printf("%lld",A);
    else
    {
        if(A==0)printf("%lld %lld",B,C);
        else if(A<0&&B>0)
        {A++;B=C-B;printf("%lld %lld %lld",A,B,C);}
        else if(A>0&&B<0)
        {A--;B=C+B;printf("%lld %lld %lld",A,B,C);}
        else printf("%lld %lld %lld",A,B,C);
    }
    return 0;
}
