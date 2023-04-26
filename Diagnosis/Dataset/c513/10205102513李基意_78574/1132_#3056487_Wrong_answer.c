#include<stdio.h>

int main(){
    int T,n,r,m,a[32];
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d%d",&n,&r);
        if(n<r) m=n;
        while((n>r)&&(n%r)){
            m+=n%r;
            n/=r;
        }
        printf("case #%d:\n",i);
        int j = 0;
        while (m > 0) {
        a[j] = m % 2;
        j = j + 1;
        m = m / 2;
        }
        for (j--; j >= 0; j--)
            printf("%d", a[j]);
        printf("\n");
    }
    return 0;
}