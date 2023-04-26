#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int len;
    long int arr[50];
}D;

int cmp(const void*a,const void*b)
{
    D aa=*(D*)a,bb=*(D*)b;
    int i=0;
    for(;i<aa.len&&i<bb.len;i++)
    {
        if(aa.arr[i]>bb.arr[i]) return -1;
        else if(aa.arr[i]<bb.arr[i]) return 1;
    }
    if(i==aa.len) return 1;
    else if(i==bb.len) return -1;
    return 0;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N=0;
        scanf("%d",&N);
        D*d=(D*)malloc(sizeof(D)*N);
        for(int i=0;i<N;i++)
        {
            int j=0;
            do
            {
                scanf("%ld",&d[i].arr[j]);
                j++;
            }while(d[i].arr[j-1]!=-1);
            d[i].len=j-1;
        }
        qsort(d,N,sizeof(d[0]),cmp);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<d[i].len;j++)
                printf("%ld%c",d[i].arr[j],j==d[i].len-1?'\n':' ');
        }
        free(d);
    }
    return 0;
}
