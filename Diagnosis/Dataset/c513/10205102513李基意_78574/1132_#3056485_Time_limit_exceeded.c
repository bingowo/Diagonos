#include<stdio.h>

int main(){
    int T,n,r,m=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d%d",&n,&r);
        if(n<r) m=n;
        while((n>r)&&(n%r)){
            m+=n%r;
            n/=r;
        }
        printf("case #%d:\n",i);
        int i = 0, a[32];
        while (m > 0) {
        a[i] = m % 2;
        i = i + 1;
        n = n / 2;
        }
        for (i--; i >= 0; i--)
            printf("%d", a[i]);
        printf("\n");
    }
    return 0;
}