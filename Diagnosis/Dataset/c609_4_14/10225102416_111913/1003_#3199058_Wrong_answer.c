#include<stdio.h>

int change(long long N);
int main()
{
    int T,i;
    long long N[100000];
    scanf("%d",&T);  //T表示测试数据的数量
    for(i = 0;i<T;i++){
        scanf("%lld",&N[i]);  //N表示要转换的数
    }
    for(i = 0;i<T;i++){
        change(N[i]);
    }
    return 0;
}
int change(long long N)
{
    int a[100000];
    int i = 0;
    if(N == 0) a[0]=0;
    else{
        while(N){
            a[i]=N%2333;
            N = N/2333;
            i++;
        }
    }
    for(int n = i-1;n>= 0;n--){
        printf("%lld ",a[n]);
    }
    printf("\n");
    return 0;
}
