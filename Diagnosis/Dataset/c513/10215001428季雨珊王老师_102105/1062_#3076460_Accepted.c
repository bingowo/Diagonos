#include<stdio.h>
#include<math.h>
long long a[51]={0,1,2,4,8};
long long ways(int num){
    for(int i=5;i<=num;i++){
        a[i]=a[i-1]+a[i-2]+a[i-3]+a[i-4];
    }
    return a[num];
}
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n;
        scanf("%d",&n);
        long long result=ways(n);
        printf("case #%d:\n%lld\n",t,result);
    }
    return 0;
}