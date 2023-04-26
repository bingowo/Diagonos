#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int GCD(int m,int n)
{
    return (n?GCD(n,m%n):m);
}
int main()
{
    char s[100];
    scanf("%s",s);
    unsigned int n=0;
    long long A=0,B=0,C=1;
    for(;n<strlen(s);n++)
    {
        if(s[n]=='.') break;
        A=A*3;
        if(s[n]=='1') A+=1;
        if(s[n]=='2') A-=1;
    }
    n++;
    for(;n<strlen(s);n++)
    {
        B=B*3;
        if(s[n]=='1') B+=1;
        if(s[n]=='2') B-=1;
        C=C*3;
    }
    if(A>0 && B<0)
    {
        A--;
        B=C+B;
    }
    if(A<0 && B>0)
    {
        A++;
        B=C-B;
    }
    if(A==0) B=-B;
    long long m=GCD(abs(B),abs(C));
    printf("%lld\n",m);
    if(B==0) printf("%lld\n",A);
    else
    {
        if(A!=0) printf("%lld\n",A);
        printf("%lld %lld\n",B/m,C/m);
    }
    return 0;
}
