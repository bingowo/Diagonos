#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct hash
{
    double len;
    double ang;
};

typedef struct hash res;

const double pi=3.14159;

void solve(double a,double b,res* idx)
{
    idx->len=pow(a*a+b*b,0.5);
    if(b>=0)
        idx->ang=acos(a/idx->len);
    else
        idx->ang=2*pi-acos(a/idx->len);
}

int cmp(const void* a,const void* b)
{
    res m=*(res*)a;
    res n=*(res*)b;
    if(m.ang==n.ang)
    {
        if(m.len<n.len) return 1;
        else return -1;
    }
    else
    {
        if(m.ang<n.ang) return -1;
        else return 1;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int N;
        scanf("%d",&N);
        res ans[N];
        for(int i=0;i<N;i++)
        {
            double a,b;
            scanf("%lf %lf",&a,&b);
            solve(a,b,&ans[i]);
        }
        qsort(ans,N,sizeof(ans[0]),cmp);
        for(int i=0;i<N;i++)
        {
            printf("(%.4f,%.4f)\n",ans[i].len,ans[i].ang);
        }
    }
    return 0;
}
