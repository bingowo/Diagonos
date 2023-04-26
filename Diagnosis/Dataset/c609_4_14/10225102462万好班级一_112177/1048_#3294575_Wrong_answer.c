//数组法
#include<stdio.h>

typedef struct number{int arr[31];} Big;

int main()
{
    int n;scanf("%d",&n);
    Big fib[n+1];
    for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < 31; ++j) {
            fib[i].arr[j] = 0;
        }fib[1].arr[30] = 1;fib[2].arr[30] = 1;
    }//数组的初始化

    for ( int i = 2; i <= n; i++)//从第一项开始
    {
        for (int k = 30; k > 0; --k) {
            fib[i].arr[k] = fib[i].arr[k] + (fib[i-1].arr[k] + fib[i-2].arr[k])%10;
            fib[i].arr[k-1] = fib[i].arr[k-1] + (fib[i-1].arr[k] + fib[i-2].arr[k])/10;
        }
    }

    int bool = 0;
    for (int i = 0; i < 31; ++i) {
        if(fib[n].arr[i] == 0 && bool == 0)continue;
        else {bool = 1;printf("%d",fib[n-1].arr[i]);}
    }printf("\n");
}
