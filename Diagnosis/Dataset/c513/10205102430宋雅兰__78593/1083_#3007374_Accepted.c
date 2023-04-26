#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        int j=5,ans=0;
        while(j<=n)
        {
            int m=j;
            while(m%10==0)
            {
                ans++;
                m/=10;
            }
            while(m%5==0)
            {
                ans++;
                m/=5;
            }
            j++;
        }
        printf("case #%d:\n%d\n",i,ans);
    }
    return 0;
}