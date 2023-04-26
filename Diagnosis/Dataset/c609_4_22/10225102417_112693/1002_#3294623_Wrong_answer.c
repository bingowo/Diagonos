#include <stdio.h>
#include <stdlib.h>

int max_len(long long a)
{
    int fir=a%2,sec;
    int count=1;
    int temp=1;
    while(a)
    {
        a>>=1;
        sec=a%2;
        if(sec !=fir){temp++;}
        else
        {
            if(temp>count){count=temp;}
            temp=1;
        }
        fir=sec;
    }
    if(temp>count){count=temp-1;}


    return count;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        long long a;
        scanf("%lld",&a);
        printf("case #%d\n",i);
        printf("%d\n",max_len(a));
    }
    return 0;
}
