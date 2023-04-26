#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int data;
    int order;
}arr;

int cmp1(const void *q1,const void *q2)
{
    arr *p1=(arr *)q1;
    arr *p2=(arr *)q2;

    return p1->order-p2->order;
}

int cmp2(const void *q1,const void *q2)
{
    arr *p1=(arr *)q1;
    arr *p2=(arr *)q2;

    return p1->data-p2->data;
}

int main()
{
    int m,n;
    int a[1008]={0};
    arr b[666]={0};

    scanf("%d\n",&m);
    for(int i=0;i<m;i++)
        scanf("%d",&a[i]);

    scanf("%d\n",&n);
    for(int j=0;j<n;j++)
        scanf("%d",&b[j].data);

    int k=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(b[i].data==a[j])
            {
                b[k].order=j;
                int t1=b[i].data;
                b[i].data=b[k].data;
                b[k].data=t1;
                k++;
            }

    qsort(b,k,sizeof(b[0]),cmp1);
    qsort(b+k,n-k,sizeof(b[0]),cmp2);

    for(int i=0;i<n;i++)
        printf("%d ",b[i].data);

    return 0;
}
