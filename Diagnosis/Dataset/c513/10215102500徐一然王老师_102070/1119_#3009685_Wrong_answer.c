#include <stdlib.h>
#include <stdio.h>

typedef struct {int k,v;}car;

int cmp(const void*a, const void *b)
{
    car* p1=(car *)a;
    car* p2=(car *)b;
    if(p1->k<p2->k)return -1;
    else return 1;
}

int main()
{
    int d;
    scanf("%d",&d);
    int n;
    scanf("%d",&n);
    car A[1100];
    car *p=A;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&A[i].k,&A[i].v);
    }
    qsort(p,n,sizeof(A[0]),cmp);
    /*for(int i=0;i<n;i++)
    {
        printf("%d %d\n",A[i].k,A[i].v);
    }*/
    int flag=0;double ans=0;double t;int i=0;
    for(i=0;i<n-1;i++)
    {
        if(A[i].v>A[i+1].v)
        {
            if((double)(A[i+1].k-A[i].k)/(double)(A[i].v-A[i+1].v)>(double)((double)(d-(A[i+1].k))/A[i+1].v)){flag=i;}
               else flag=i+1;
        }
        else
        {
            flag=i;
        }
        t=d/((double)(d-(A[flag].k))/A[flag].v);
        if(t>ans)
        {
            ans=t;
        }
    }
    //printf("%d %d\n",flag,A[flag].k);
    printf("%.6lf",ans);
}
