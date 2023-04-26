#include<stdio.h>
long long a[75];
long long tribo(int n){
    if(n==0)
        return 0;
    if(n==1||n==2)
        return 1;
    if(a[n])
        return a[n];
    return tribo(n-1)+tribo(n-2)+tribo(n-3);
}
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n;
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",t,tribo(n));
    }
    return 0;
}
