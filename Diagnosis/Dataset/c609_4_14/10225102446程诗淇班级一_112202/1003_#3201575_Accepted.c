#include <stdio.h>
void f(long long int a){
    long long int m;
    if(a/2333!=0){

        f(a/2333);

    }
    m=a%2333;
    printf("%lld ",m);

}


int main(){
    int T;
    scanf("%d",&T);
    int i;
    long long int b;
    for(i=0;i<T;i++){
        scanf("%lld",&b);
        f(b);
        printf("\n");
    }
    return 0;
}



