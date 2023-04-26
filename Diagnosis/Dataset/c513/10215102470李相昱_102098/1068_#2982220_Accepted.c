#include <stdio.h>
#include <math.h>
long long int fun(int n,int m){
    if(n<m){
        return 0;
    }
    if(m==n){
        return 1;
    }
    return 2* fun(n-1,m)- fun(n-1-m,m)+ (int)pow(2,n-m-1);


}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    while (n!=-1&&m!=-1){
        printf("%lld\n", fun(n,m));
        scanf("%d%d",&n,&m);
    }
    return 0;
}