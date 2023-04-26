#include<stdio.h>
int f(long long n){
    int max=1, temp=1, ret;
    ret = n%2;
    n /=2;
    while(n!=0){
        if(n%2!=ret){
            temp++;
            ret = n%2;
        }else{
            if(temp>max) max = temp;
            temp = 1;
        } 
        n /= 2;
    }
    if(temp>max) max = temp;
    return max;
}
int main(){
    int T;
    scanf("%d", &T);
    long long n;
    for(int i=0; i<T; i++){
        scanf("%lld", &n);
        printf("case #%d:\n", i);
        printf("%d\n", f(n));
    }

    return 0;
}