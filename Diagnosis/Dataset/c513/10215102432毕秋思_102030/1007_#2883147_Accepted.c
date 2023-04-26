#include <stdio.h>

int func(long long int n)
{
    int fir=n%2,sec,count=1,temp=1;
    while(n)
    {
        n>>=1;
        sec=n%2;
        if(sec!=fir) temp++;
        else
        {
            if(temp>count)
            {
                count=temp;
            }
            temp=1;
        }
        fir=sec;
    }
    if(temp>count) count=--temp;
    return count;
}

int main()
{
    int T,ans;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        long long int n=0;
        scanf("%d",&n);
        ans=func(n);
        printf("case #%d:\n",i);
        printf("%d\n",ans);
    }
    return 0;
}
