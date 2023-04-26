#include <stdio.h>

int max_len_dif(long long a)
{
    int fir=a%2,sec,count=1,temp=1;
    while(a)
    {
        a>>=1;
        sec=a%2;
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
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        long long int n;
        scanf("%d",&n);
        ans=max_len_dif(n);
        printf("case #%d:\n",i);
        printf("%d\n",ans);
    }
    return 0;
}
