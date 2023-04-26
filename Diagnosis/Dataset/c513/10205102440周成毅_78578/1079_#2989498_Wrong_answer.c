#include <stdio.h>
#include <stdlib.h>



int cmp(const void *a, const void *b){
    int *a1=(int *)a,*b1=(int *)b;
    return *a1-*b1;
}

int main() {
    int T;
    int num[1001];
    int sum[501505];
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n,m,l,u;
        scanf("%d %d",&n,&m);
        for(int j=1;j<=n;j++)
            scanf("%d",&num[j]);
        printf("case #%d:\n",i);
        int tmp=0,co=0;
        int len=(n*(n+1)/2);
        int *p=(int *)malloc(sizeof (int)*(len+1));
        for(int j=1;j<=n;j++){
            for(int k=j;k<=n;k++){
                tmp+=num[k];
                p[co++]=tmp;
            }
            tmp=0;
        }
        qsort(p,len,sizeof (int),cmp);
        tmp=0,co=1;
        sum[0]=0;
        for(int j=0;j<len;j++){
            tmp+=p[j];
            sum[co++]=tmp;
        }
        for(int j=0;j<m;j++){
            scanf("%d %d",&l,&u);
            printf("%d\n",sum[u]-sum[l-1]);
        }
    }
    return 0;
}
