#include<stdio.h>
#include<stdlib.h>
int main(){
    int  t;
    scanf("%d",&t);
    while(t--){
        long long n;
        scanf("%lld",&n);
        int a[100]={0};
        int i=0,j;
        while(n){
            a[i++]=n%2333;
            n/=2333;
        
        }
        for(j=i-1;j>0;j--){
            printf("%d",a[j]);
        }
        printf("%d\n",a[j]);
    }
    return 0;
}