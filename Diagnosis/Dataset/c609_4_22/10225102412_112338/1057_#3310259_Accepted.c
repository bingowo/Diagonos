#include <stdio.h>

int calc(int n)
{
    int i,t,f,a,b;
    t=f=0;
    for (i=2;i<=n;i+=2){
        a = i;
        while (a%2==0){
            a = a/2;
            t++;
        }
    }
    for (i=5;i<=n;i+=5){
        b = i;
        while (b%5==0){
            b = b/5;
            f++;
        }
    }
    if (t>f) return f;
    else return t;
}

int main()
{
    int T,i,n;
    scanf("%d",&T);
    for (i=0;i<T;i++){
        scanf("%d",&n);
        printf("case #%d:\n%d\n",i,calc(n));
    }
    return 0;
}