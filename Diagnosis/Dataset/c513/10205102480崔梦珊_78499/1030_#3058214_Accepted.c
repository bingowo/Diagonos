#include<stdio.h>
#include<stdlib.h>

struct z
{
    long long data;
    int c;
};

int cmp(const void* a,const void* b)
{
    struct z* x=(struct z*)a;
    struct z* y=(struct z*)b;
    if(x->c==y->c)
    {
        if(x->data>y->data)
        {
            return 1;
        }
        return -1;
    }
    return y->c-x->c;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        struct z ans[10001];
        int N;
        scanf("%d",&N);
        for(int j=0;j<N;j++)
        {
            scanf("%lld",&ans[j].data);
            long long temp=ans[j].data;
            if(ans[j].data<0)
            {
                temp=-ans[j].data;
            }
            while(temp/10!=0)
            {
                temp=temp/10;
            }
            ans[j].c=temp;
        }
        qsort(ans,N,sizeof(ans[0]),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<N-1;k++)
        {
            printf("%lld ",ans[k].data);
        }
        printf("%lld\n",ans[N-1].data);
    }
}
