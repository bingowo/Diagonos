#include<stdio.h>
#include<stdlib.h>


struct line
{
    int data[51];
    int n;
};

int cmp(const void* a,const void* b)
{
    struct line* x=(struct line*)a;
    struct line* y=(struct line*)b;
    int p=0;
    while(x->data[p]==y->data[p])
    {
        p++;
    }
    return y->data[p]-x->data[p];
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        struct line ans[1001];
        for(int j=0;j<N;j++)
        {
            int a;
            int k=0;
            while(scanf("%d",&a)&&a!=-1)
            {
                ans[j].data[k]=a;
                k++;
            }
            ans[j].data[k]=-10;
            ans[j].n=k;
        }
        qsort(ans,N,sizeof(ans[0]),cmp);
        for(int j=0;j<N;j++)
        {
            for(int m=0;m<ans[j].n-1;m++)
            {
                printf("%d ",ans[j].data[m]);
            }
            printf("%d\n",ans[j].data[ans[j].n-1]);
        }
    }

}
