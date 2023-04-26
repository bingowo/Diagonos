#include <stdio.h>
#include <stdlib.h>
int count(int n)
{
    int num1=0;
    while(n!=0)
    {
        n=n&(n-1);
        num1++;
    }
    return num1;
}
struct type{
    int data;
    int num;
};
int cmp(const void*a, const void*b)
{
    struct type* p1=(struct type*)a;
    struct type* p2=(struct type*)b;
    if(p1->num==p2->num)
    {
        return p1->data-p2->data;
    }
    return p2->num-p1->num;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        struct type a[N];
        for(int j=0;j<N;j++)
        {
            scanf("%d",a[j].data);
            a[j].num=count(a[j].data);
        }
        qsort(a,N,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int m=0;m<N;m++)
            printf("%d ",a[m].data);
    }
    return 0;
}
