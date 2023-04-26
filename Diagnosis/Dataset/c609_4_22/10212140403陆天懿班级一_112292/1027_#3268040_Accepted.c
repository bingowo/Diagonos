#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>

typedef long long ll;
typedef unsigned long long ull;

#define N 505
#define M 15
ll a[N],num[N],c[M];
int r[N];
int n,m,gn;
ll g;

int Cmp(const int* pa, const int* pb){
    if(a[*pa]!=a[*pb]) return a[*pb]-a[*pa];
    return num[*pa]<num[*pb]?-1:1;
}

int main(){
    int pros;
    scanf("%d",&pros);
    for(int cnt=0;cnt<pros;cnt++){
        scanf("%d%d%lld",&n,&m,&g);
        gn=0;
        for(int i=1;i<=m;i++) scanf("%lld",c+i);
        for(int i=0,j,k;i<n;i++){
            scanf("%lld%d",num+gn,&k);
            a[gn]=0;
            while(k--){
                scanf("%d",&j);
                a[gn]+=c[j];
            }
            if(a[gn]>=g) gn++;
        }
        for(int i=0;i<gn;i++)
            r[i]=i;
        qsort(r,gn,sizeof(r[0]),Cmp);
        printf("case #%d:\n",cnt);
        printf("%d\n",gn);
        for(int i=0;i<gn;i++)
            printf("%011lld %lld\n",num[r[i]],a[r[i]]);
    }

    return 0;
}
