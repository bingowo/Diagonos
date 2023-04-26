#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        int ans=1;
        for(int j=1;j<=x;j++)
        {
            ans*=j;
        }
        int tump=0;
        while(ans)
        {
            if(ans&1==0) tump++;
            ans>>=1;
        }
        printf("case #%d:\n%d\n",i,tump);
    }
    return 0;
}