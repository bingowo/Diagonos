#include<stdio.h>

int main()
{
    int t;
    int n;
    scanf("%d",&t);

    for (int i=0;i<t;++i)
    {
        scanf("%d",&n);

        long long res=0;
        for (int w=0;w<=n/4;++w)
        {
            for (int x=0;x<=n/3;++x)
            {
                for (int y=0;y<=n/2;++y)
                {
                    if (4*w+3*x+2*y<=n)
                    {
                        res++;
                        
                    }
                }
            }
        }

        printf("%lld\n",res);
    }
}