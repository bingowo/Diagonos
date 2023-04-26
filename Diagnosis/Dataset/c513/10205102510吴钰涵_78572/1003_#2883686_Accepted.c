#include <stdio.h>
#include <stdlib.h>

int num(long long int x) {  //求得数的二进制数中1的个数
    int cnt=0;
    while(x) {
        x=x&(x-1);
        cnt++;
    }
    return cnt;
}

int cmp(const void *a,const void *b) {  //标准格式,返回值小于0时不用调换，否则调换
    long long int *p1=(long long int *)a;  ////将 void 类型指针转换为 long long int 类型指针
    long long int *p2=(long long int *)b;
    long long int a0=*p1,b0=*p2;  //取得指针所指地址的数据
    int a1=num(a0);
    int b1=num(b0);
    if(a1==b1) {
        if(a0>b0)
            return 1;
        else
            return -1;
    }
    else if(a1>b1)
        return -1;
    else
        return 1;
}

int main()
{
    int T,N;
    scanf("%d",&T);
    for(int I=0;I<T;I++)
    {
        scanf("%d",&N);
        long long *L=(long long *)malloc(N*sizeof(long long));
        for(int i=0;i<N;i++) {
            scanf("%lld",&L[i]);
        }
        qsort(L,N,sizeof(long long),cmp);  //四个参数分别为：数组名，数组中元素个数，sizeof(相应数据类型）
        printf("case #%d:\n",I);
        for(int i=0;i<N;i++)
            printf("%lld ",L[i]);
        printf("\n");
    }
    return 0;
}
