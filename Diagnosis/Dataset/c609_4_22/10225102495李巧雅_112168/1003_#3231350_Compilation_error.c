#include <stdio.h>
#include <string.h>
int main
{
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        long long n,a[1000]={0},num=0;
        scanf("%lld",&n);
        while(n)
        {
            a[num]=n%2333;
            a[++num]=' ';
            n/=2333;
        }
        int e,f,t;
        for(e=0,f=num-1;e<f;e++,f--)
        {
            t=a[e];
            a[e]=a[f];
            a[f]=t;
        }
        printf("%s\n",a);.
    }
    return 0;
}