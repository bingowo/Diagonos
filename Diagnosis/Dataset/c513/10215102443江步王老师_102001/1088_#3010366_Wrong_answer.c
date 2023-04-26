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
                
                if (j%small_top ==0)
                {
                    unsigned long long times=j/small_top;
                    res*=times;
                    //printf("res=%d\n",res);
                    //printf("small=%d\n",small_top);
                    small_top--;
                }
                else
                {
                    res*=j;
                    //printf("res=%d\n",res);
                }
            }

            for (j=small_top;j>0;--j)
            {
                res/=j;
                printf("res=%d\n",res);
            }
        }
        

        printf("case #%d:\n",i);
        printf("%lld\n",res);
    }
    return 0;
}