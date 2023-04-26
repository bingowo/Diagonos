#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b,t=1,ans=0,ta,tb;
        scanf("%d %d",&a,&b);
        for(int i=0;i<31;i++)
        {
            ta=a&t?1:0;
            tb=b&t?1:0;
            if((ta^tb)) ans++;
            t=t<<1;
        }
        ta=a&t?1:0;
        tb=b&t?1:0;
        if((ta^tb)) ans++;
        printf("%d\n",ans);
    }
}