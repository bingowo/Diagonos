#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    long long int num;
    int none;
}node;
int get(long long int a){
    int ret=0;int d=1;
    for(int i=0;i<64;i++){
        if(a&d)ret++;
        d<<=1;
    }
    return ret;
}
int cmp(const void *a,const void *b){//返回值为true,两元素交换位置
    node x=*(node*)a;
    node y=*(node*)b;
    if(x.none==y.none)return x.num-y.num;//升序
    return y.none-x.none;//降序
}
int main(){
    int t;scanf("%d",&t);getchar();
    int cas=0;
    while(t--){
        int n;scanf("%d",&n);getchar();
        node *data=(node*)malloc(sizeof(node)*n);
        for(int i=0;i<n;i++){
            scanf("%lld",&data[i].num);
            data[i].none=get(data[i].num);
        }
        qsort(data,n,sizeof(data[0]),cmp);
        printf("case #%d:\n",cas++);
        for(int i=0;i<n;i++){
            printf("%lld",data[i].num);
            if(i==n-1)putchar('\n');
            else putchar(' ');
        }
    }
}