#include<stdio.h>

int change(int N);
int main()
{
    int T,N[100000],i;
    scanf("%d",&T);  //T表示测试数据的数量
    for(i = 0;i<T;i++){
        scanf("%d",&N[i]);  //N表示要转换的数
    }
    for(i = 0;i<T;i++){
        change(N[i]);
    }
    return 0;
}
int change(int N)
{
    int a[1000];
    int i = 0,flag = 0;
    if (N<0){
        N = -N;
        flag = 1;
    }
    while(N){
        a[i]=N%2333;
        N = N/2333;
        i++;
    }
    if(flag == 1) a[i]='-';
    for (int n = i-1;n>= 0;n--){
        printf("%d ",a[n]);
    }
    printf("\n");
    return 0;
}