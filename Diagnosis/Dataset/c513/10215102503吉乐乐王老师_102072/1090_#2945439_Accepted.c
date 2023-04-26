#include<stdio.h>
#include<math.h>
int main(){
    int n;
    while(scanf("%d",&n)==1&&n!=0){
        double a=n*log10(n)-(int)(n*log10(n));
        int ret=pow(10,a);
        printf("%d\n",ret);
    }
}