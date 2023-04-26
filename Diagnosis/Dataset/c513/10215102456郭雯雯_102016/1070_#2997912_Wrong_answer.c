#include<stdio.h>
#include<math.h>

int main(){
    int n;
    scanf("%d",&n);
    while(n!=-1){
        long long num;
        if(n==1)num=2;
        if(n==2)num=4;
        if(n==3)num=7;
        if(n>3)num=3*pow(2,n-2);
        printf("%lld\n",num);
        scanf("%d",&n);
    }
}