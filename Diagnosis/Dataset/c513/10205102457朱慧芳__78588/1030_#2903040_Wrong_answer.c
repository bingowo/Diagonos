#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
    long long int data;
    int high;
}number;

int high_number(long long int n)
{
    long long int nn=n;
    if(n<0) nn=-n;
    int h,i;
    for(i=0;nn!=0;i++)
        nn=nn/10;
    h=n/(pow(10,i-1));
    if(n<0) h=-h;
    return h;
}
int cmp(const void* a,const void *b)
{
    number* p1=(number*)a;
    number* p2=(number*)b;
    if(p1->high==p2->high)
        return (long long int*)(p1->data)-(long long int*)(p2->data);
    return p2->high-p1->high;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        number a[N];
        for(int j=0;j<N;j++)
        {
            scanf("%lld",&a[j].data);
            a[j].high=high_number(a[j].data);
        }
        qsort(a,N,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int m=0;m<N;m++)
            printf("%lld ",a[m].data);
        printf("\n");
    }
    return 0;
}
