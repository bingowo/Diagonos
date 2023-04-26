#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int T;
    scanf("%d",&T);
    int n;
    for(int cas=0;cas<T;cas++)
    {
        scanf("%d",&n);
        int cnt=0;
        for(int w=0;w<=n/4;w++)
        {
            for(int x=0;x<=n/3;x++)
            {
                for(int y=0;y<=n/2;y++)
                {
                    if(4*w+3*x+2*y<=n) cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
