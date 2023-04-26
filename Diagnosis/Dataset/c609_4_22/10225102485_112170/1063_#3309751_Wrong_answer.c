#include<stdio.h>
#include<stdlib.h>
long long int func(long long int a){
    long long int arr[100];
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    arr[3]=4;
    for(int i=4;i<100;i++){
        arr[i]=arr[i-1]+arr[i-2]+arr[i-3]+arr[i-4];
    }
    return arr[a];
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        long long int a;
        scanf("%lld\n",&a);
        printf("case #%d:\n",i);
        printf("%lld",func(a));
    }
}
