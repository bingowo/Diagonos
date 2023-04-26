#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        long long num=0;
        scanf("%d",&n);
        for(int w=0;w<=n/4;w++)
        {
            for(int x=0;x<=n/3;x++)
            {
                for(int y=0;y<=n/2;y++)
                {
                    for(int z=0;z<=n;z++)
                    {
                        if(4*w+3*x+2*y+z==n)
                            num++;
                    }
                }
            }
        }
        printf("%lld\n",num);
    }
    return 0;
}