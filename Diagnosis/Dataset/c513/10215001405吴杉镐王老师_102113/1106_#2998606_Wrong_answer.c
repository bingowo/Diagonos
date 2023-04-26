#include <stdio.h>
#include <string.h>
#define M 1000000007

int main()
{
    long long res=1;
    char a,b,c;
    a=getchar();
    b=getchar();
    if(a!=b && b!=-1)
        res=2;
    while((c=getchar())!=EOF)
    {
        if(a!=b && b!=c)
            res=res*3%M;
        else if(a!=b && b==c)
            res=res*2%M;
        else if(b!=c && a==b)
            res=res*2%M;
        else if(a!=c && b!=a)
            res=res*2%M;
        a=b;
        b=c;
    }
    if(b!=a)
        res=res*2%M;
    printf("%lld",res);
}
