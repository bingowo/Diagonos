#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long gcd(long long x, long long y)
{
    if(y)
        return gcd(y,x%y);
    else
        return x;
}

int main()
{
    long long A=0,B=0,C=1;
    char s[32];
    int ptr=0;
    long long t;

    scanf("%s",&s);
    for(;ptr<strlen(s);ptr++)
    {
        if(s[ptr]=='.')break;
        A=A*3;
        if(s[ptr]=='1') A+=1;
        if(s[ptr]=='2') A-=1;
    }
    ptr++;
    for(;ptr<strlen(s);ptr++)
    {
        C*=3;
        B*=3;
        if(s[ptr]=='1')
            B+=1;
        if(s[ptr]=='2')
            B-=1;
    }
    if(A>0&&B<0)
    {
        A--;
        B+=C;
    }
    else if(A<0&&B>0)
    {
        A++;
        B=C-B;
        if(A==0)
            B=-B;
    }

    t=gcd(abs(C),abs(B));
    
    if (B==0) 
        printf("%lld\n",A);
    else
    {   
        if (A!=0) printf("%lld ",A);
        printf("%lld %lld\n",B/t,C/t);
    }

    system("pause");
    return 0;
}