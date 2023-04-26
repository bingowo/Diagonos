#include <stdio.h>
#include <stdlib.h>



long long r=2333;

int main()
{
    long long a[3];
    long long n;
    int T;int i=0;
    scanf("%d",&T);
    while(T>0)
    {
        scanf("%lld",&n);
        long long p=n;
        a[0]=0;
        while(p){
            a[i]=p%r;
            p=p/r;
            i++;
        }
        if(i!=0) i=i-1;
        while(i>=0){
            if(i==0)
                printf("%lld\n",a[i]);
            else printf("%lld ",a[i]);
            i--;
        }
        i=0;
        T--;
    }
    return 0;
}

