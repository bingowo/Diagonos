#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
   return *(int*)a - *(int*)b;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0;i < t;t++){
        printf("case #%d:\n",t);
        int n,m;
        scanf("%d%d",&n,&m);
        int in[1001] = {0};
        long long int out[500501] = {0};
        int cnt = 0;
        for(int j = 1;j<=n;j++){
            scanf("%d",in + j);
            in[j] += in[j-1];
        }
        for(int len = 1;len <= n;len++){
            for(int k = 1;k <= n - len + 1;k++)
                out[++cnt] = in[k + len - 1] - in[k - 1];
        }
        qsort(out,n*(n-1)/2,sizeof(long long int),cmp);
        for(int i = 1;i<= cnt;i++)
            out[i] += out[i-1];
        for(int i = 0;i<m;i++){
            int l,u;
            scanf("%d%d",&l,&u);
            printf("%lld\n",out[u] - out[l-1]);
        }

    }
    return 0;
}
