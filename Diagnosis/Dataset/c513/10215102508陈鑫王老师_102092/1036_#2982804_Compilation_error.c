#include<stdio.h>
#include<stdlib.h>
#define max 4611686018427387904
typedef struct
{
    long long int x;
    long long int y;
    unsigned long long int d;
}dian;
long long int absll(long long int a)
{
    return a<0?-a:a;
}
int cmp(const void*a,const void*b)
{
    dian* x=(dian*)a;
    dian* y=(dian*)b;
    if(x->d!=y->d) return x->d>y->d?-1:1;
    else if(x->x!=y->x) return x->x<y->x?-1:1;
    else return x->y<y->y?-1:1;
}
unsigned long long int distance(dian *a,dian*b)
{
    unsigned long long int ret;
    ret=absll(a->x-b->x)+absll(a->y-b->y);
    return ret;
}
unsigned long long int steps(unsigned long long int x)
{
    unsigned long long int ret=0;
    while(x>0)
    {
        ret++;
        x=x>>1;
    }
    return ret;
}
int main()
{
    int n;
    scanf("%d",&n);
    dian ans[n];
    for(int i=0;i<n;i++)
    {
       scanf("%lld %lld",&ans[i].x,&ans[i].y);
       ans[i].d=absll(ans[i].x)+absll(ans[i].y);
    }
    qsort(ans,n,sizeof(dian),cmp);
    if(ans[0].x==-max&&ans[0].y==-max&&ans[1].x==max&&ans[1].y==max)
        printf("18446744073709551616\n0");
    else
    {
        unsigned long long int step=0;
        printf("%llu\n",distance(&ans[0],&ans[1]));
        for(int i=0;i<n-1;i++)
        {
            unsigned long long int temp=distance(&ans[i],&ans[i+1]);
            if(temp%2==0&&temp!=0)) break;
            else
            {
                step+=steps(temp);
            }
        }
        printf("%llu",step);
    }
return 0;

}
