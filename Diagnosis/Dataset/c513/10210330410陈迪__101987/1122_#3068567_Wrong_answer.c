#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        long long n;
        scanf("%lld",&n);
        int ans[10],k=0;
        do
        {
            ans[k++]=n%2333;
            n/=2333;
        }while(n);
        for(k=k-1;k>=0;k--)
        {
            printf("%d",ans[k],k==0?"\n":" ");
        }
    }
    return 0;
}
