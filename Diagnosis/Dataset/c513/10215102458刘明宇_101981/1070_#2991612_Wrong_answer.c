#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//写一个函数来统计出现101字符串的个数
double f(int n)
{
    double sum0 = 0;
    if(n == 3) return 1;
    if(n < 3) return 0;
    sum0 += f(n-1);
    int x = n;
    while(x >= 6){
        sum0 += f(x-3);
        x--;
    }
    for(int i = n-3;i>=0;i--){
        sum0+=pow(2.0,i);
    }
    return sum0;
}

int main()
{
    int n;
    scanf("%d",&n);
    double sum = f(n);
    printf("%.0f\n",pow(2.0,(double)n)- sum);
}
