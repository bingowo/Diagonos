#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10000
int cmp(const void* a,const void* b)
{
    int* pa=(int*)a;
    int* pb=(int*)b;
    return (*pa>*pb?-1:1);
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        long long n;
        scanf("%lld",&n);
        int j,k,arr[N]={0};
        int fir=n%2,sec;
        int count=1,tmp=1;
        for (j=0;n/2>0 || n==1;j++)
        {
            n=n>>1;
            sec=n%2;
            if (sec!=fir) tmp++;
            else
            {
                if (tmp>count) count=tmp;
                tmp=1;
            }
            fir=sec;
        }
        if (tmp>count) count=--tmp;
        printf("%d\n",count);

    }
    return 0;
}
