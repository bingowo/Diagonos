#include<stdio.h>
#include<stdlib.h>
struct cir
{
    int r;
    int h;
    long long int ce;
    long long int di;
};
int cmp(void *a,void *b)
{
    if(((struct cir *)a)->ce>((struct cir *)b)->ce) return -1;
    if(((struct cir *)a)->ce==((struct cir *)b)->ce) return 0;
    if(((struct cir *)a)->ce<((struct cir *)b)->ce) return 1;
}
int cmp1(void *a,void *b)
{
    long long int *a1;
    long long int *b1;
    a1=(long long int *)a;
    b1=(long long int *)b;
    if(*a1>*b1) return -1;
    if(*a1==*b1) return 0;
    if(*a1<*b1) return 1;
}
int main()
{
    int sum,choose;
    scanf("%d",&sum);
    struct cir cirs[2000];
    scanf("%d",&choose);
    for(int i=0;i<sum;i++)
    {
        scanf("%d %d",&cirs[i].r,&cirs[i].h);
        cirs[i].ce=2*cirs[i].r*cirs[i].h;
        cirs[i].di=cirs[i].r*cirs[i].r;
    }
    qsort(cirs,sum,sizeof(cirs[0]),cmp);
    long long int res[2000];
    for(int i=0;i<sum;i++)
    {
        int tmp=choose-1;
        int j=0;
        res[i]=cirs[i].di+cirs[i].ce;
        while(tmp)
        {
            if(j!=i && cirs[i].di>=cirs[j].di)
            {
                res[i]=res[i]+cirs[j].ce;
                tmp--;
            }
            j++;
        }
    }
    qsort(res,sum,sizeof(res[0]),cmp1);
    printf("%lld",res[0]);
}