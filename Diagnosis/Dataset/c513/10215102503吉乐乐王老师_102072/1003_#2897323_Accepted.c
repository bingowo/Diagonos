#include<stdio.h>
#include<stdlib.h>
int get(long long int a){
    int ret=0;
    for(int i=0;i<64;i++){
        if(a&1)ret++;
        a>>=1;
    }
    return ret;
}
int cmp(const void *a,const void *b){//返回值为true,两元素交换位置
    long long int x=*(long long int *)a;
    long long int y=*(long long int *)b;
    if(get(x)==get(y))return x>y?1:-1;//升序
    return get(x)<get(y)?1:-1;//降序
}
int main(){
    int t;scanf("%d",&t);getchar();
    int cas=0;
    while(t--){
        long long int n;scanf("%lld",&n);getchar();
        long long int *data=(long long int*)malloc(sizeof(long long int)*n);
        for(int i=0;i<n;i++){
            scanf("%lld",data+i);
        }
        qsort(data,n,sizeof(data[0]),cmp);
        printf("case #%d:\n",cas++);
        for(int i=0;i<n;i++){
            printf("%lld",data[i]);
            if(i==n-1)putchar('\n');
            else putchar(' ');
        }
    }
}