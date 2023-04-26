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
        for (j=0;n/2>0 || n==1;j++)
        {
            arr[j]=n%2;
            n=n/2;
        }
        int count=1,h=0;
        int c[32]={0};
        for (k=1;k<j;k++)
        {
            if (arr[k]!=arr[k-1]) count++;
            else
            {
                c[k]=count;
                h=1;
                count=1;
            }

        }
        qsort(c,sizeof(c)/sizeof(int),sizeof(int),cmp);
        printf("%d\n",h==1?c[0]:count);

    }
    return 0;
}
