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
        int ans=0;
        for(int j=1;j<N+1;j++)
        {
            int m=j;
            while(m%5==0)
            {
                ans++;
                m=m/5;
            }
        }
        printf("case #%d:\n%d\n",i,ans);
    }
}
