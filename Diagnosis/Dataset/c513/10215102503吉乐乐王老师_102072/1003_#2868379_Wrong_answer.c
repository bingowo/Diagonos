#include<stdio.h>
#include<stdlib.h>
int get(long long int x){
    int cnt=0;
    for(int i=0;i<80;i++){
        if(x&1)cnt++;
        x=x>>1;
    }
    return cnt;
}
int cmp(const void *a,const void *b){
    long long int x=*(int *)a;
    long long int y=*(int *)b;
    if(get(x)==get(y)){
        return x>y?1:-1;
    }
    return get(x)<get(y)?1:-1;
}
int main(){
    int t;
    scanf("%d",&t);
    int idx=0;
    while(t--){
        long long int n;
        scanf("%lld",&n);
        long long int *num=(long long int *)malloc(sizeof(long long int)*n);
        for(int i=0;i<n;i++){
            scanf("%lld",(num+i));
        }
        qsort(num,n,sizeof(long long int),cmp);
        printf("case #%d:\n",idx++);
        for(int i=0;i<n;i++){
            printf("%lld",*(num+i));
            if(i==n-1)printf("\n");
            else printf(" ");
        }
    }
}