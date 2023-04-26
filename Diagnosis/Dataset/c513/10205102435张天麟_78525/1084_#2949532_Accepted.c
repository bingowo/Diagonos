#include<stdio.h>
int main()
{
    int T,n;
    scanf("%d",&T);
    for(n=0;n<T;n++)
    {
        int N,i;
        long long ans=1;
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            ans*=2;
        }
        printf("case #%d:\n%lld\n",n,ans);
    }
    return 0;
}
