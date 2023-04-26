#include<stdio.h>

int main()
{
    
    int m,n;
    int t;
    int i,j;

    scanf("%d",&t);

    for(i=0;i<t;++i)
    {
        unsigned long long res=1;
        scanf("%d %d",&m,&n);
        if (n!=0)
        {
            int large_bottom,small_top;
            if (m>2*n)
            {
                large_bottom=n;
                small_top=m-n;
            }
            else
            {
                large_bottom=m-n;
                small_top=n;
            }

            for (j=m;j>large_bottom;--j)
            {
                if (j == 2*small_top)
                {
                    res*=2;
                    small_top--;
                }
                else
                {
                    res*=j;
                }
            }

            for (j=small_top;j>0;--j)
            {
                res/=j;
            }
        }
        

        printf("case #%d:\n",i);
        printf("%lld\n",res);
    }
    return 0;
}