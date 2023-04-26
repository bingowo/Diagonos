#include <stdio.h>
#include <stdlib.h>
struct cylinder
{
    long long int r;
    long long int h;
    long long int carea;
    long long int darea;
};

int cmp(const void *a,const void*b)
{
    struct cylinder *m = (struct cylinder *)a;
    struct cylinder *n = (struct cylinder *)b;
    if(m->carea > n->carea)
        return -1;
    else if(n->carea > m->carea)
        return 1;
    else return 0;
}
int main()
{
    int m,n,i,j;
    scanf("%d %d",&n,&m);
    struct cylinder c[1001]={0};
    for(i=0;i<n;i++)
    {
        scanf("%lld",&c[i].r);
        scanf("%lld",&c[i].h);
        c[i].carea=(2*c[i].r)*c[i].h;
        c[i].darea=c[i].r*c[i].r;
    }
    qsort(c,i,sizeof(c[0]),cmp);
    long long int ans=0;
    long long int max=0;
    for(i=0;i<n;i++)
    {
        int count = 1;
        ans=c[i].carea+c[i].darea;
        for(j=0;j<n && count<m ;j++)
        {
            if(i==j || c[i].r < c[j].r) continue;
            ans += c[j].carea;
            count ++;
        }
        max = max>ans ? max:ans;
    }
    printf("%lld",max);
    return 0;
}