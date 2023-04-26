#include<stdio.h>
#include<stdlib.h>
int get(int t){
    int cnt=0;
    int i;
    for(i=0;i<64;i++){
        if(t&1){
            cnt++;
            t=t>>1;
        }
    }
    return cnt;
}
int cmp(int a,int b){
    return get(a)<get(b);
}
int main(){
    int t;
    scanf("%d",&t);
    int cnt=0;
    while(t--){
        int idx;
        long long int num[10000];
        int n;
        scanf("%d",&n);
        int i;
        for(i=0;i<n;i++){
            scanf("%lld",num[i]);
        }
        qsort(num,n,sizeof(long long int),cmp);
        for(i=0;i<n;i++){
            printf("%d",num[i]);
            if(i==n-1)printf("\n");
            else printf(" ");
        }
    }
}