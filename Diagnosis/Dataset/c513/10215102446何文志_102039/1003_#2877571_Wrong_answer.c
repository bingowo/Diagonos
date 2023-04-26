#include <stdio.h>
#include <stdlib.h>

int cmp1(const void *a,const void *b)
{
    long long ta = *(long long*)a,tb = *(long long*)b;
    int a1 = get1Number(a),b1 = get1Number(b);
    //printf("a = %d,resa = %d,b = %d,resb = 0\n",ta,a1,tb,b1);
    return  b1 - a1;
}

int get1Number(long long n)
{
    int res = 0;
    unsigned long long temp = 1;
    while(temp)
    {
        if(n&temp){res++;}
        temp = temp<<1;
    }
    return res;
}

int main()
{
    int T = 0;
    scanf("%d",&T);
    //long long n = -10;
    //printf("%d\n",-11/2);
    //printf("%d\n",get1Number(n));
    int i = 0;
    for(i = 0;i<T;i++)
    {
        int N = 0;
        scanf("%d",&N);
        long long* arr = (long long*)malloc(10000*sizeof(long long));
        memset(arr,0,10000*sizeof(long long));
        //printf("T = %d N = %d\n",T,N);

        for(int j = 0;j<N;j++)
        {
            scanf("%lld",&arr[j]);
        }

        qsort(arr, N, sizeof(long long), cmp1);
        for(int j = 0;j<N;j++)
        {
            printf("%lld ",arr[j]);
        }


        free(arr);
    }
    return 0;
}
