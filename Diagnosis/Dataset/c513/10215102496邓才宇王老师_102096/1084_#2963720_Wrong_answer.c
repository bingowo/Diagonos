#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        long long int ans=1;
        for(int j=0;j<N;j++)
        {
            ans=ans*2;
        }
        printf("case #%d\n%lld\n",i,ans);
    }
}
