#include <stdio.h>
#include <stdlib.h>

int main()
{
    int up[21];
    int down[21];
    int sum[21];
    int a,n,m,x;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    up[0] = a;
    down[0] = 0;
    sum[0] = a;
    int t = 0;
    while(t<=m){
        up[1] = t;
        down[1] = t;
        sum[1] = a;
        for(int i = 2;i<n;i++){
            up[i] = up[i-1] + up[i-2];
            down[i] = up[i-1];
            sum[i] = sum[i-1]+up[i] - down[i];
        }
        if(sum[n-2] == m){
            printf("%d\n",sum[x-1]);
        }
        t++;
    }
}
