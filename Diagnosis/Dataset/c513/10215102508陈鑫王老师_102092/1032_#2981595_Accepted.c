#include<stdio.h>
#include<stdlib.h>
struct num
{
    int a[51];
};
int cmp(const void* a,const void*b)
{
    struct num* x=(struct num*)a;
    struct num* y=(struct num*)b;
    int index=0;
    for(;x->a[index]==y->a[index];index++);
    return x->a[index]>y->a[index]?-1:1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        struct num ret[n];
        for(int j=0;j<n;j++)
        {
            int temp=0;
            for(int k=0;temp!=-1&&k<51;k++)
            {
                scanf("%d",&temp);

                ret[j].a[k]=temp;
            }

        }
        qsort(ret,n,sizeof(ret[0]),cmp);
        for(int j=0;j<n;j++)
        {

            for(int k=0;k<51&&ret[j].a[k]!=-1;k++)
            {
              printf("%d%c",ret[j].a[k],ret[j].a[k+1]==-1?'\n':' ');
            }
        }

    }
    return 0;
}
