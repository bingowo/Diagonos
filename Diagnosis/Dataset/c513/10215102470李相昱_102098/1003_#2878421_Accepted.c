#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void*b);
int main() {
    int t;
    scanf("%d",&t);
    for(int i = 0;i<t;i++){
        int n;
        scanf("%d",&n);
        long long int b[10000];
        for(int j =0;j<n;j++){
            scanf("%lld",&b[j]);
        }
        qsort(b,n,sizeof(long long int),cmp);
        printf("case #%d:\n",i);
        for(int m=0;m<n;m++){
            printf("%lld",b[m]);
            if(m !=n-1){
                printf(" ");
            } else
                printf("\n");
        }
    }
    return 0;
}

int cmp(const void *a,const void*b){
    long long int a1= *((long long int*)a);
    long long int b1= *((long long int*)b);
    int ret1 = 0,ret2=0;
    long long int cnt =1;
    for(int i = 0;i<64;i++){
        if((a1 & (cnt<<i)) !=0){
            ret1++;
        }
        if ((b1 & (cnt<<i)) !=0){
            ret2++;
        }
    }
    if(ret1==ret2){
        return a1>b1?1:-1;
    }
    return ret2-ret1;
}