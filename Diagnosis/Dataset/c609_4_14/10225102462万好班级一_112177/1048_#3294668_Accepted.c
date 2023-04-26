//数组法
#include<stdio.h>

typedef struct number{int arr[31];} Big;

void put_down(int * ans,int flag)
{
    while(flag > 0)
    {if(ans[flag] < 10){flag--;continue;}ans[flag-1] += ans[flag]/10;ans[flag] = ans[flag]%10;flag--;}
}

int main()
{
    int loop;scanf("%d",&loop);
    for (int g = 0; g < loop; ++g) {

        int n;scanf("%d",&n);
        if(n == 0){printf("case #%d:\n0\n",g);continue;}
        Big fib[122];
        //数组的初始化
        for (int i = 0; i < 122; ++i) {
            for (int j = 0; j < 31; ++j) {
                fib[i].arr[j] = 0;
            }
        }fib[1].arr[30] = 1;fib[2].arr[30] = 1;
        for ( int i = 3; i <= n; i++)//从第一项开始
        {
            for (int k = 30; k > 0; --k) {
                fib[i].arr[k] =fib[i-1].arr[k] + fib[i-2].arr[k];
            }put_down(fib[i].arr,30);
        }
        printf("case #%d:\n",g);
        int bool = 0;
        for (int i = 0; i < 31; ++i) {
            if(fib[n].arr[i] == 0 && bool == 0)continue;
            else {bool = 1;printf("%d",fib[n].arr[i]);}
        }printf("\n");
    }

}
