#include <stdio.h>
#include <stdlib.h>

long long Sigma(long long *p,long long n)
{
    if(n == 1) return p[0];
    else return Sigma(p,n-1) + p[n-1];
}//前n项和
int cmp(const void*a,const void*b)
{
    int *pa,*pb;
    pa = (int *)a;
    pb = (int *)b;
    return *pa - *pb;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n,m;
        scanf("%d%d",&n,&m);
        long long ary[n],cnt = 0,tmp0 = n;
        while(tmp0--){
            scanf("%lld",&ary[cnt++]);
        }
        cnt = 0;
        int len = n*(n+1)/2;
        long long subs[len];
        long long *p = ary;
        while(n){
            int tmp = n;
            while(tmp){
                subs[cnt++] = Sigma(p,tmp);
                tmp--;
            }
            n--;
            p++;
        }
        qsort(subs,len,sizeof(subs[0]),cmp);
        //printf("%lld",Sigma(subs,3));
        for(int j=0;j<m;j++){
            int L,U;
            scanf("%d%d",&L,&U);
            long long *ps = subs;
            ps += --L;
            if(j == 0)  printf("case #%d:\n",i);
            printf("%lld\n",Sigma(ps,U-L));
        }
    }
    return 0;
}