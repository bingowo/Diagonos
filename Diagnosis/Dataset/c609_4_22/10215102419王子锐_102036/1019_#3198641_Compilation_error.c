#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct data
{
    int dig;
    int val;
};
int getDig (int val)
{
    val = abs(val);
    int ans = 0;
    while (val){
        ans ++;
        val /= 10;
    }
    return ans;
}
int cmp(const void *a,const void *b){
    struct data d1,d2;
    d1=*((struct data *)a);
    d2=*((struct data *)b);
    if (d1.dig != d2.dig)
        return d1.dig > d2.dig;
    return d1.val < d2.val;
}
void solve(){
    struct data p[10000];
    while(scanf("%d",&p[i].val)!=EOF)
    {
        p[i].dig = getDig(p[i]].val);
    }
    qsort(p,N,sizeof(p[0]),cmp);
    for(int i=0; i<N; i++)
    printf("%lld%c",p[i].a,(i==N-1?'\n':' '));
    
}
int main()
{
    int n=0;
    struct data p[10000];
    while(scanf("%d",&p[n++].val)!=EOF)
    {
        p[n].dig = getDig(p[n]].val);
    }
    qsort(p,n,sizeof(p[0]),cmp);
    for(int i=0; i<n; i++)
    printf("%d%c",p[i].val,(i==n?'\n':' '));
    return 0;
    
}