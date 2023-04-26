#include <stdio.h>
#include <stdlib.h>

long long Sigma(long long *p,int n)
{
    long long S = 0;
    for(int i=0;i<n;i++){
        S += p[i];
    }
    return S;
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
            ps = ps+L-1;
            if(j == 0)  printf("case #%d:\n",i);
            printf("%lld\n",Sigma(ps,U-L+1));
        }
    }
    return 0;
}
