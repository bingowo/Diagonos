#include<stdio.h>
#include<stdlib.h>
struct data{
    long long int a;
    int cnt;};
int cmp(const void *a,const void *b){
    struct data *x=(struct data*)a;
    struct data *y=(struct data*)b;
    if(x->cnt<y->cnt)return 1;
    return -1;
}
int main(){
    int t;
    scanf("%d",&t);
    int idx=0;
    while(t--){
        int n;
        scanf("%d",&n);
        struct data num[10000];
        for(int i=0;i<n;i++){
            scanf("%lld",&num[i].a);
            int d=1;
            int ret=0;
            for(int i=0;i<64;i++){
                if(num[i].a&d)ret++;
                d=d<<1;
            }
            num[i].cnt=ret;
        }
        qsort(num,n,sizeof(struct data),cmp);
        printf("case #%d:\n",idx++);
        for(int i=0;i<n;i++){
            printf("%d",num[i].a);
            if(i==n-1)printf("\n");
            else printf(" ");
        }
    }
}