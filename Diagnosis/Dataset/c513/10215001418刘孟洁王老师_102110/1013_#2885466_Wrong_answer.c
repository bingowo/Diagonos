#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 1000000
int GCD(int m,int n)
{
    if(m%n==0)return n;
    else if(n%m==0)return m;
    else if(m>n)m=m-n;
    else if(n>m)n=n-m;
    return GCD(m,n);
}

int main()
{
    long long int A=0,B=0,C=1;
    int i;
    char s[N];
    scanf("%s",s);
    for(i=0;s[i]!='.';i++)
    {
        A=A*3+s[i]-'0';
    }
    i++;
    for(;i<strlen(s);i++)
    {
        B=B*3+s[i]-'0';
        C=C*3;
    }
    int t=GCD(B,C);
    B=B/t;C=C/t;
    if(A<0&&B<0)B=-B;
    else if(A<0&&B>0){A++;B=C-B;}
    else if(A>0&&B<0){A--;B=C+B;}
    if(A==0)printf("%lld %lld",B,C);
    else if(B==0)printf("%lld",A);
    else printf("%lld %lld %lld",A,B,C);
    return 0;
}
