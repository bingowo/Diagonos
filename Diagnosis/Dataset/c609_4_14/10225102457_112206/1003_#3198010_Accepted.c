#include<stdio.h>
#include<stdlib.h>
int main()
{
    int out[8];
    long long in;
    int T;
    scanf("%d",&T);

    for(int i = 0;i < T;i++){
        scanf("%lld",&in);
        long long m;
        int n = 0;
        out[n] = in%2333;
        while(in /= 2333){
            n++;
            out[n] = in%2333;
        }
        for(;n >= 0;n--) printf("%d ",out[n]);
        putchar('\n');
    }
    return 0;
}