#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    long long x;
    int i,j,a[100];
    while(T--){
        i=0,j=0;
        scanf("%lld",&x);
        do{
            a[i++]=x%2333;
            x=x/2333;
        }while(x);
        for(j=i-1;j>=0;j--)
            printf("%lld ",a[j]);
        printf("\n");
    }
    return 0;
}
