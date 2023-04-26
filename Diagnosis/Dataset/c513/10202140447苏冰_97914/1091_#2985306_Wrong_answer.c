#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main()
{
    char s[20];
    int n;
    scanf("%s",s);
    scanf("%d",&n);
    int sign=0,i,j=0;
    long long x=0,a,b;
    if(s[0]=='-') j=1;
    for(i=j;i<strlen(s);i++)
    {
        if(isdigit(s[i]))
        {
            x=x*10+(s[i]-'0');
        }
        else
        {
            if(s[i]=='+')
            {
                sign=1;
                if(j==1) a=-x;
                else a=x;
                x=0;
            }
            else if(s[i]=='-')
            {
                sign=-1;
                if(j==1) a=-x;
                else a=x;
                x=0;
            }
            else if(s[i]=='i'&& sign==0)
            {
                a=0;
                if(j==1)
                {
                    if(x==0) b=-1;
                    else b=-x;
                }
                else
                {
                    if(x==0) b=1;
                    else b=x;
                }
                break;
            }
            else if(s[i]=='i' && sign!=0)
            {
                if(sign==1)
                {
                    if(x==0) b=1;
                    else b=x;
                }
                else if(sign==-1)
                {
                    if(x==0) b=-1;
                    else b=-x;
                }
                break;
            }
        }
    }
    if(i==strlen(s))
    {
        if(j==1) a=-x;
        else a=x;
        b=0;
    }
    long long A=a,B=b;
    for(int i=0;i<n-1;i++)
    {
        long long x=A*a-B*b;
        long long y=A*b+B*a;
        A=x;
        B=y;
    }
    if(n==0) printf("1\n");
    else
    {
        if(A==0 && B==0) printf("%d",0);
        if(A!=0) printf("%lld",A);
        if(B!=0)
        {
            if(B>0 && A!=0)
            {
                printf("+");
            }
            if(B!=1 && B!=-1) printf("%lld",B);
            if(B==-1) printf("-");
            printf("i");
        }
    }
    return 0;
}

