#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a1,const void* b1)
{
    int *a=(int*)a1;
    int *b=(int*)b1;
    while(*a!=-1 && *b!=-1 && *a==*b)
    {
        a++;
        b++;
    }
    return *b-*a;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
        int N;
        scanf("%d",&N);
        int a[1005][55];//二维数组
        for(int j=0; j<N; j++)
        {
            int k=0;
            while(scanf("%d",&a[j][k]) && a[j][k]!=-1)
            {
                k++;
            }
        }

        qsort(a,N,sizeof(a[0]),cmp);
        for(int j=0; j<N; j++)
        {
            int k=0;
            while(a[j][k+1]!=-1)
            {
                printf("%d ",a[j][k]);
                k++;
            }
            printf("%d\n",a[j][k]);
        }
    }

    return 0;
}



