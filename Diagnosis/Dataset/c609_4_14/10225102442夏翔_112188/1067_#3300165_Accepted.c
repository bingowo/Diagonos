//1067
/*
上车人数a   x   a+x   a+2x   2a+3x   3a+5x
下车人数0   x   x     a+x    a+2x    2a+3x
总人数  a   a   2a    2a+x   3a+2x   4a+4x  */
#include<stdio.h>
typedef struct{
    int a;
    int X;
}F;
F up[25], sum[25];
int main(){
    int a, n, m, x, X;
    scanf("%d %d %d %d", &a, &n, &m, &x);
    up[1].a=1; up[1].X=0; 
    up[2].a=0; up[2].X=1;
    for(int i=3; i<n; i++){  //计算上车人数
        up[i].a = up[i-1].a+up[i-2].a;
        up[i].X = up[i-1].X+up[i-2].X;
    }
    sum[1].a = 1; sum[1].X = 0;
    sum[2].a = 1; sum[2].X = 0;
    for(int i=2; i<n-1; i++){//上车到n-1站，计算总人数
        sum[i+1].a = sum[i].a+up[i-1].a;
        sum[i+1].X = sum[i].X+up[i-1].X;
    }
    X = (m-sum[n-1].a*a)/sum[n-1].X; //n-1站的人数就是n
    printf("%d\n", sum[x].a*a+sum[x].X*X);
    return 0;
}