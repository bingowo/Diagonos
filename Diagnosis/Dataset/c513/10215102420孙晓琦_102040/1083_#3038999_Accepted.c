#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n,ans=0;
        scanf("%d",&n);
        for(int j=1;j<=n;j++)
        {
            int n=j,m=5;
            while(n>=m)
            {
                if(n%m==0)
                {
                    ans+=1;
                    n=n/m;
                }
                else
                    break;
            }
        }
        printf("case #%d:\n%d\n",i,ans);
    }
}
