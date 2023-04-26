#include<stdio.h>

int weighable(int a,int *w,int n){
    if(!a) return 1;
    if(!n) return 0;
    return weighable(a-*w,w+1,n-1)||weighable(a+*w,w+1,n-1)||weighable(a,w+1,n-1);
}

int main(){
    int i,T,w[10],total=0;
    for(scanf("%d",&T),i=0;i<T;i++){
        scanf("%d",w+i);
        total+=w[i];
    }
    for(i=1;i<=total;i++){
        printf("%ld",weighable(i,w,T));
    }
    return 0;
}
