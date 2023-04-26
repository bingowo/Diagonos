#include <stdio.h>
#include <stdlib.h>

int f(long long n)
{
    int maxlen=1,i=1,j=0;
    while(n)
    {
        if((n%2) !=((n/2)%2))
        {
            if((n/2)%2==0 && maxlen<i) maxlen=i;
            i++;
        }
        else
        {
            if(i>maxlen) maxlen=i;
            i=1;
        }
        n/=2;
    }
    return maxlen;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        long long n;
        scanf("%lld",&n);
        printf("case #%d:\n",i);
        printf("%d\n",f(n));
    }
    return 0;
}
