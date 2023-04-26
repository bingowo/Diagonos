#include <stdio.h>
#include <math.h>
long long f(int n, int p, int m, int t){
    if(abs(t-p)>m){return 0;}
    if(m==0 && t!=p){return 0;}
    if(m==0 && t==p){return 1;}
    if(m>0 && t==1){return f(n, p, m-1, 2);}
    if(m>0 && t==n){return f(n, p, m-1, n-1);}
    return f(n, p, m-1, t-1) + f(n, p, m-1, t+1);
}
int main(){
    int T; scanf("%d", &T);
    int n, p, m, t;
    for(int i = 0; i<T; i++){
        scanf("%d%d%d%d",&n, &p, &m, &t);
        if(t>n){printf("0\n");continue;}
        printf("%lld\n", f(n, p, m, t));
    }
    return 0;
}