#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct F101
{
    long long _old;
    long long _new;
    long long _01;
    long long _0101;
}f101;

int main()
{
    int n = 0;
    while(n>=0)
    {
         scanf("%d",&n);
         f101 f[n];memset(f,0,n*sizeof(f101));
         f[0]._old = 0;f[0]._new = 0;
         f[1]._old = 0;f[1]._new = 0;
         f[2]._old = 0;f[2]._new = 1;
         f[3]._old = 2;f[3]._new = 2;
         f[4]._old = 8;f[4]._new = 3;
         for(int i = 5;i<n;i++)
         {
             f[i]._old = 2*f[i-1]._old+2*f[i-1]._new;
             f[i]._new = (1<<(i-2)) - (1<<(i-4));
             printf("fnew = %lld\n",f[i]._new);                                            ;
         }
         for(int i = 0;i<n;i++)
         {
             printf("f[%d]: old = %lld, new = %lld\n"
                    ,i,f[i]._old,f[i]._new);
         }
         long long tmp1 = 1;
         long long res = (1<<n)-f[n-1]._old-f[n-1]._new;
         printf("res = %lld\n",res);
         printf("ddd %d\n",1<<0);

    }
    return 0;
}
