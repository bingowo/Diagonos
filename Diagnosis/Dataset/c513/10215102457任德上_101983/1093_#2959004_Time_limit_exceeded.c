#include<stdio.h>
int find_nine(long long int i){
    while(i>0LL){
        if(i%10LL==9LL)return 1;
        i/=10LL;
    }
    return 0;
}
int main(){
    long long int a,i;
    scanf("%lld",&a);
    i=a+1LL;
    for(;;i++){
        if(i%9LL!=0LL&&find_nine(i)==0)break;
    }
    printf("%lld",i);
    return 0;
}