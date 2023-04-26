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
        int num=0;
        scanf("%d",&n);
        for (int w=0;w<=n/4;w++)
        {
            for (int x=0;x<=n/3;x++)
            {
                for (int y=0;y<=n/2;y++)
                {
                    if (4*w+3*x+2*y<=n)
                            num++;
                }
            }
        }
        printf("%d\n",num);
    }
    return 0;
}