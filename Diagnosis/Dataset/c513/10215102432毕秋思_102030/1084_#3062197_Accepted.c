#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int N;
        scanf("%d",&N);
        int ans=1;
        for(int n=0;n<N;n++)
        {
            ans*=2;
        }
        printf("case #%d:\n",t);
        printf("%d\n",ans);
    }
    return 0;
}
