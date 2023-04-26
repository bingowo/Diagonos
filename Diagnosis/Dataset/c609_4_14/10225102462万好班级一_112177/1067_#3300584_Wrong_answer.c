#include <stdio.h>

void fib_(int fib[],int sum){
    fib[0] = 1;fib[1] = 1;
    for (int i = 2; i < sum - 1;i++)
        fib[i] = fib[i-1]+ fib[i-2];
}

int main(){
    int start,sum,last,tar;
    scanf("%d %d %d %d",&start,&sum,&last,&tar);
    int fib[sum-2];fib_(fib,sum);
    int x;int x_list[sum-1];
    for (int i = 0; i < sum-1; ++i) {
        if(i < 3)x_list[i] = 0;
        else x_list[i] = x_list[i-1] + fib[i-1] - fib[i-2];
    }
    x = (last - (fib[sum-2] - x_list[sum-2])*start)/x_list[sum-2];
    printf("\n%d",x_list[tar-1]*x + (fib[tar-1] - x_list[tar-1])*start);
}