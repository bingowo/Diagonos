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

            int* t1 = (int* )malloc(sizeof(int)*(m+1));
            int* t2 = (int* )malloc(sizeof(int)*small_top);
            int* flag = (int* )malloc(sizeof(int)*small_top);
            for (k=0;k<=m;++k)
            {
                flag[k]=0;
            }
            for (j=small_top;j>0;)
            {
                for (k=m;k>large_bottom;k--)
                {
                    if (!(k%j) && !(flag[k]))
                    {
                        int times=k/j;
                        res*=times;
                        j--;
                        flag[k]=1;
                        break;
                    }
                }
            }
        }
        
        printf("case #%d:\n",i);
        printf("%lld\n",res);
    }
    return 0;
}