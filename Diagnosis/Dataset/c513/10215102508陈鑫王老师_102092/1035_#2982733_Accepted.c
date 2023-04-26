#include<stdio.h>
#include<stdlib.h>
typedef struct
{
     long long int r;
   long long int h;
   long long int s1;
   long long int sall;

}yuan;
int cmp(const void*a,const void*b)
{
    yuan*x=(yuan*)a;
    yuan*y=(yuan*)b;
    return x->s1<y->s1?1:-1;

}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    yuan ans[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld",&ans[i].r,&ans[i].h);
        ans[i].s1=2*ans[i].r*ans[i].h;
        ans[i].sall=ans[i].s1+ans[i].r*ans[i].r;
    }
    qsort(ans,n,sizeof(yuan),cmp);
    long long int maxret=0;
    for(int i=0;i<n;i++)
    {
        long long int ret;
        ret=ans[i].sall;
        int temp=1;
        for(int j=0;j<n&&temp<m;j++)
        {
            if(j==i||ans[i].r<ans[j].r) continue;
            ret+=ans[j].s1;
            temp++;
        }
        if(temp==m)
            maxret=maxret>ret?maxret:ret;


    }
    printf("%lld",maxret);
    return 0;

}