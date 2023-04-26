#include <stdio.h>
#include <stdlib.h>

int num=0;
long int f(long int n)
{
    long int fanshu=0,x=n;
    while(x>0)
    {
        fanshu=fanshu*10+x%10;
        x/=10;
    }
    if(fanshu==n) return n;
    else{num+=1,f(fanshu+n);}
}

int main()
{
    long int n=0;
    scanf("%ld",&n);
    printf("%d %ld",num,f(n));
    return 0;
}
