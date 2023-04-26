#include<stdio.h>
#include<malloc.h>

int main()
{
    
    int m,n;
    int t;
    int i,j,k;

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

            int* t1 = (int* )malloc(sizeof(int)*small_top);
            int* t2 = (int* )malloc(sizeof(int)*small_top);
            int* flag = (int* )malloc(sizeof(int)*small_top);
            for (k=0;k<small_top;++k)
            {
                flag=0;
            }
            for (j=m;j>large_bottom;--j)
            {
                for (k=small_top;k>0;--k)
                {
                    if (!(j%k) && !(flag[k]))
                    {
                        int times=j/k;
                        flag[k]=1;
                        res*=times;
                    }
                }
            }
        }
        
        printf("case #%d:\n",i);
        printf("%lld\n",res);
    }
    return 0;
}