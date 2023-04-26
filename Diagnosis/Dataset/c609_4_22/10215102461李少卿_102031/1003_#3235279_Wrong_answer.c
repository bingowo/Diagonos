#include<stdio.h>
#define x 2333
#define max 100000
int main(){
    int T;
    scanf("%d",&T);
    while(T-->0){
        long long int a;
        int b[max];
        int i=0;
        scanf("%lld",&a);
        while(a>0){
            b[i++]=a%x;
            a=a/x;
        }
        for(int j=i-1;j>=0;j--){
            printf("%d ",b[j]);
        }
         printf("\n");
    }
    return 0;
}