#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LL long long
LL Solve(int n);

int main(){
    int T;
    scanf("%d", &T); // 输入问题数T
    LL total[51] = {0};
    for(int i = 0; i < T; i++){
        int n;
        scanf("%d", &n);//输入台阶数
        *(total + i) = Solve(n);// 递归
        printf("case #%d:\n%d\n", i, *(total + i));
    }
    Solve(4);
    return 0;
}

LL Solve(int n){
    if(n < 1)
        return 0;
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    if(n == 3)
        return 4;
    if(n == 4)
        return 8;
    return (Solve(n-1)+Solve(n-2)+Solve(n-3)+Solve(n-4));//算到34就溢出了, 极限为33
}
