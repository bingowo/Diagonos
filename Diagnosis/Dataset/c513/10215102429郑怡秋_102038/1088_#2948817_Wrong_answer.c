#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("case #%d:\n",i);
        int x,y;
        scanf("%d%d",&x,&y);
        if(y==0) printf("1\n");
        else 
        {
            long long ans=1;
            long long chu=1;
            for(int j=1;j<=y;j++)
            {
                chu*=j;
            }
            for(int j=x;j>x-y;j--)
            {
                ans*=j;
            }
            printf("%lld\n",ans/chu);
        }
        
    }
    return 0;
}