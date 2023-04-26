#include <stdio.h>
#include <stdlib.h>

struct row
{
    int a[60];
};

int cmp(const void*a,const void*b)
{
    struct row*ap=(struct row*)a;
    struct row*bp=(struct row*)b;
    int i;
    for(i=0;;i++)
    {
        if(ap->a[i]!=bp->a[i])
            return (bp->a[i]-ap->a[i]);
        if(ap->a[i]==-1)
            return 1;
        if(bp->a[i]==-1)
            return -1;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        struct row b[1000];
        int j,p;
        for(j=0;j<N;j++)
        {
            for(p=0;;p++)
            {
                scanf("%d",&b[j].a[p]);
                if(b[j].a[p]==-1)
                    break;
            }
        }
        qsort(b,N,sizeof(struct row),cmp);
        for(j=0;j<N;j++)
        {
            for(p=0;b[j].a[p]!=-1;p++)
                printf("%d ",b[j].a[p]);
            printf("\n");
        }
    }
}
