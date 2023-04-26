#include <stdio.h>
#include <string.h>
#include <stdlib.h>
long long GCD(long long a,long long b)
{
    while(b%a)
    {
        long long t=b%a;
        b=a;
        a=t;
    }
    return a;
}
int main()
{
    char s[32];
    scanf("%s",s);
    long long A=0,B=0,C=1;
    int len=strlen(s),i=0;
    for (;i<len;i++)
    {
        if (s[i]=='.') {i++;break;}
        int t=0;
        if (s[i]=='1') t=1;
        else if(s[i]=='2') t=-1;
        A=A*3+t;
    }
    for (;i<len;i++)
    {
        int t=0;
        if (s[i]=='1') t=1;
        else if(s[i]=='2') t=-1;
        B=B*3+t;
        C*=3;
    }
     if(A && B<0)
    {
        A--;
        B=C+B;
    }
    else if(A<0 && B>0)
    {
        A++;
        B=C-B;
        if(A==0) B=-B;
    }
    if(B==0)
    {
        printf("%lld\n",A);
    }
    else{
    long long t=GCD(abs(B),abs(C));
        if(A!=0)
        {
            printf("%lld ",A);
        }
        printf("%lld %lld\n",B/t,C/t);
    }
    return 0;
}
