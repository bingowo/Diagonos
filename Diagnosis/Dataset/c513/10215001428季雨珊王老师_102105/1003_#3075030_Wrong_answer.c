#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int numof1(long long n){
    int d=1,count=0;
    for(int i=0;i<64;i++){
        if(n&d)
            count++;
        d<<=1;
    }
    return count;
}

struct NUMBER{
    long long number;//原数
    int count;//1的位数
}*a;

int cmp(void const *a,void const *b){
    struct NUMBER* aa=(struct NUMBER*)a;
    struct NUMBER* bb=(struct NUMBER*)b;//强制类型转换
    if((aa->count)!=(bb->count)){
        return (bb->count)-(aa->count);
    }
    else
        return (aa->number)-(bb->number);
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int N;
        scanf("%d",&N);
        a=(struct NUMBER*)malloc(sizeof(struct NUMBER)*N);
        for(int i=0;i<N;i++){
            scanf("%lld",&a[i].number);
            a[i].count=numof1(a[i].number);
        }
        qsort(a,N,sizeof(a[0]),cmp);
        printf("case #%d:\n",t);
        for(int i=0;i<N;i++){
            printf("%lld ",a[i].number);
        }
        printf("\n");
    }
    return 0;
}
