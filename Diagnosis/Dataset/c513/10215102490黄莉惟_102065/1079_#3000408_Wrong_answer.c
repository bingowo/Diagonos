#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int cmp(const void* a,const void* b){   
    long long int ua=*(long long int*)a;
    long long int ub=*(long long int*)b;
    return ua<ub?1:-1;
}
int main(){
    int T,i,k,j,len,t;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        int a[1001]={0};
        long long int b[500501]={0};
        int m,n;
        int L,U;
        printf("case #%d:\n",i);
        scanf("%d %d",&m,&n);
        int cnt=0;
        for(j=1;j<=n;j++) {scanf("%d",a+j);a[j]+=a[j-1];}
        for(len=1;len<=n;len++)
            for(t=1;t<=n-len+1;t++)
                b[++cnt]=a[t+len-1]-a[t-1];
        qsort(b,cnt,sizeof(b[0]),cmp);  //数组b排序
        for(t=1;t<=cnt;t++) b[t]+=b[t-1];
        for(k=0;k<m;k++){
            scanf("%d %d",&L,&U);
            printf("%lld\n",b[U]-b[L-1]);
        }
    }
}
