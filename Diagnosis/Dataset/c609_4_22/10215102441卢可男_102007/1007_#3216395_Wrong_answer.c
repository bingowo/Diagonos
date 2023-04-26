#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int number_1(unsigned int n)//将参数改为无符号，这样可以正数和负数都适用
{
    int cnt=0;
    while(n)
    {
        cnt+=n%2;
        n/=2;
    }
    return cnt;
}
typedef struct Data
{
    int num;
    int cnt;
}data;
int cmp(const void*a,const void*b)
{
    data*c=(data*)a;
    data*d=(data*)b;
    if(d->cnt==c->cnt)
    {
       return c->num-d->num;
    }
    return d->cnt-c->cnt;
}
int main()
{
    int t,j;
    scanf("%d",&t);
    for(j=0;j<t;j++)
    {
        int n,i;
        scanf("%d",&n);
        data*a=(data*)malloc(sizeof(data)*n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i].num);
            a[i].cnt=number_1((unsigned int) a[i].num);

        }
        qsort(a,n,sizeof(data),cmp);
        printf("case #%d:\n",j);
        for(i=0;i<n-1;i++)
        {
            printf("%d ",a[i].num);
        }
        printf("%d\n",a[i].num);

    }


}
