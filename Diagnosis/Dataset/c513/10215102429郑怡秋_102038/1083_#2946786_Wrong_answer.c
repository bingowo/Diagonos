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
        printf("case #%d:\n%d\n",i,ans);
    }
    return 0;
}