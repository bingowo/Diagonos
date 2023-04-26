#include<stdio.h>

int change(int x,int y){
    int i = 0, n, a[32];
    for (; x > 0; x /= y) a[i++] = n % y;
    for (i--; i >= 0; i--) printf("%d", a[i]);
    return 0;
}

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
        s(m,r);
    }
    return 0;
}