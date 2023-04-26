#include<stdio.h>
#include<stdlib.h>
struct data{
    long long int a;
    int cnt;}num[10000];
int cmp(struct data a,struct data b){
    return a.cnt<b.cnt;
}
int main(){
    int t;
    scanf("%d",&t);
    int idx=0;
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lld",num[i].a);
            num[i].cnt=0;
            int d=1;
            for(int i=0;i<64;i++){
                if(num[i].a&d){
                    num[i].cnt++;
                    d=d<<1;
                }
            }
        }
        qsort(num,n,sizeof(struct data),cmp);
        printf("case #%d:\n",idx++);
        for(int i=0;i<n;i++){
            printf("%d",num[i]);
            if(i==n-1)printf("\n");
            else printf(" ");
        }
    }
}