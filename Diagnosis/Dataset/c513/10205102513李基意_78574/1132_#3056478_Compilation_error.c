#include<stdio.h>

int main(){
    int T,n,r,m=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d%d",&n,&r);
        whlie((n>r)&&(n%r)){
            m+=n%0;
            n/=r;
        }
        printf("case #%d:\n",i);
        printf(m);
    }
    return 0;
}