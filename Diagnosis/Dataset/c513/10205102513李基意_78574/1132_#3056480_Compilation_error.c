#include<stdio.h>

int main(){
    int T,n,r,m=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d%d",&n,&r);
        if(n<r) m=n;
        whlie((n>r)&&(n%r)){
            m+=n%r;
            n/=r;
        }
        printf("case #%d:\n",i);
        printf("%d",m);
    }
    return 0;
}