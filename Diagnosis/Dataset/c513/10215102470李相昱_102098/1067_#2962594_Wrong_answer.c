#include <stdio.h>
int main(){
    int T;
    long long int a[75]={0,1,1};
    for(int j=3;j<75;j++){
        a[j] = a[j-1]+a[j-2]+a[j-3];
    }
    for(int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",i,a[n]);
    }
    return 0;
}