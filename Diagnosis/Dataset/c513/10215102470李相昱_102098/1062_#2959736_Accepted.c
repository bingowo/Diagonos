#include <stdio.h>
long long int a[51]={0,1,2,4,8};
long long int Cnt(int  n){
    if(a[n]){
        return a[n];
    }
    long long int ret=Cnt(n-4)+ Cnt(n-3)+ Cnt(n-2)+ Cnt(n-1);
    a[n] = ret;
    return ret;

}
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",i,Cnt(n));
    }
    return 0;
}
