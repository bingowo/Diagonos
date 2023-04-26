#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){
    return *(int*)a>*(int*)b?1:-1;
}
int gcd(int a,int b){
    return a%b==0?b:gcd(b,a%b);
}
int main(){
    int t;
    scanf("%d",&t);
    int cas=0;
    while(t--){
        int a[1000];
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        qsort(a,n,sizeof(int),cmp);
        int b[1000];int idx=0;
        for(int i=0;i<n;i++){
            b[idx++]=a[i];
            while(i<n-1&&a[i]==a[i+1])i++;
        }
        int ret=0;
        for(int i=0;i<idx;i++){
            for(int k=i+1;k<idx;k++){
                int g=gcd(b[k],b[i]);
                if(g==1)ret++;
            }
        }
        printf("case #%d:\n%d\n",cas++,ret);
    }
}