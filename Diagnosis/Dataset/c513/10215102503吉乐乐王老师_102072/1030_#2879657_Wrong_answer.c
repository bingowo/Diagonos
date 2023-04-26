#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef long long int lli;
typedef struct{
    lli n;
    lli dig;
}node;
lli getdigit(lli a){
    if(a<0)a=-a;
    while(a>=10){
        a/=10;
    }
    return a;
}
int cmp(const void *a,const void *b){
    node x=*(node*)a;
    node y=*(node*)b;
    if(x.dig==y.dig)return x.n-y.n;
    return y.dig-x.dig;
}
int main(){
    int t;int cas=0;
    scanf("%d",&t);getchar();
    while(t--){
        int num;scanf("%d",&num);
        node *my=(node*)malloc(sizeof(node)*num);int idx=0;
        while(num--){
            scanf("%lld",&my[idx].n);my[idx].dig=getdigit(my[idx].n);
            idx++;
        }
        qsort(my,idx,sizeof(my[0]),cmp);
        printf("case #%d:\n",cas++);
        for(int i=0;i<idx;i++){
            printf("%lld",my[i].n);
            if(i==idx-1)putchar('\n');else putchar(' ');
        }
    }
}