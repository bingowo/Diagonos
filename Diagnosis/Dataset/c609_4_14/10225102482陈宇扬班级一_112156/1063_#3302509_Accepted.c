#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LL long long
LL Solve(int n);// 递归

int main(){
    int T;
    scanf("%d", &T); // 输入问题数T
    LL total[51] = {0};
    for(int i = 0; i < T; i++){
        int n;
        scanf("%d", &n);//输入台阶数
        *(total + i) = Solve(n);
        printf("case #%d:\n%lld\n", i, *(total + i));
        //printf("case #%d:\n%lld\n", i, Solve(n));
    }
    return 0;
}
// 递归
LL Solve(int n){
    LL arr[100];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    arr[4] = 8;
    for(int i = 5; i < 100; i++){
        *(arr + i) = *(arr+i-1) + *(arr+i-2) + *(arr+i-3) + *(arr+i-4);
    }
    return *(arr + n);
}
