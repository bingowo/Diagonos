#include<stdio.h>
int main()
{
    int T,n;
    scanf("%d",&T);
    for(n=0;n<T;n++)
    {
        long long ans=1;
        int wei=1,A,B,N,i;
        scanf("%d %d %d",&A,&B,&N);
        for(i=0;i<N;i++)
        {
            wei*=10;
        }
        long long mi=A%wei;
        while(B>0)
        {
            if(B%2==1)
            {
                ans*=mi;
                ans%=wei;
            }
            mi=(mi*mi)%wei;
            B/=2;
        }
        mi=ans;
        i=0;
        if(mi==0)i++;
        while(mi>0)
        {
            mi/=10;
            i++;
        }
        printf("case #%d:\n",n);
        for(;N-i>0;i++)
        {
            printf("0");
        }
        printf("%lld\n",ans);
    }
    return 0;
}
