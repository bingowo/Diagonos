#include <stdio.h>
#include <stdlib.h>

typedef struct{
     long long int a[100];
     int b;        //辅助判断一行有多少个数据
}data;

int cmp(const void*p1,const void*p2)
{
    data A=*(data*)p1;
    data B=*(data*)p2;
    int i;
    for(i=0;i<A.b&&i<B.b;i++){
        if(A.a[i]!=B.a[i]){
            return B.a[i]-A.a[i];
        }
    }
    if(i>=A.b){
        return 1;
    }else if(i>=B.b){
        return -1;
    }else{
        return 0;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N;          //一组数据的行数
        scanf("%d",&N);
        data* p=(data*)malloc(sizeof(data)*N);
        for(int j=0;j<N;j++){
            int k=0;
            while(scanf("%lld",&p[j].a[k])&&p[j].a[k]!=-1){
                k++;
            }
            p[j].b=k;
        }
        qsort(p,N,sizeof(data),cmp);
        for(int j=0;j<N;j++){
            for(int k=0;k<p[j].b;k++){
                printf("%lld ",p[j].a[k]);
            }
            printf("\n");
        }
        free(p);
    }
    return 0;
}
