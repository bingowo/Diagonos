#include <stdio.h>

int main(){
    int u[22] ={0};
    int v[22] ={0};
    int su[22] = {0};
    int sv[22]={0};
    int a;
    int t;
    int m;
    int n;
    int x;
    u[1] = 1;
    u[2] = 0;
    v[1] = 0;
    v[2] = 1;
    su[1] = 1;
    su[2] = 1;
    sv[1] = 0;
    sv[2] = 0;

    scanf("%d %d %d %d",&a,&n,&m,&x);
    for(int i = 3;i <= n-1;i++){
        u[i] = u[i-1]+u[i-2];
        v[i] = v[i-1]+v[i-2];
        su[i] = su[i-1]+v[i-1]-v[i-2];
        sv[i] = sv[i-1]+v[i]-v[i-1];
     }
     t = (m-su[n-1]*a)/sv[n-1];
    int x_total = su[x]*a + sv[x]*t;
    printf("%d",x_total);


}