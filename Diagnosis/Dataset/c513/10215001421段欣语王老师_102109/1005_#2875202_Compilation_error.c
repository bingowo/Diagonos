#include <stdio.h>
#include <stdlib.h>
#define N 50

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[N];
        double ans=0;
        printf("case #%d:\n",i);
        while(scanf("%s",s))
        {
            int k=0;
            for(j=2;s[j];j++)k++;
            for(int j=k;j>=0;j--)ans=ans/3+s[j];
            printf("%lld",ans);
        }
    }
    return 0;
}