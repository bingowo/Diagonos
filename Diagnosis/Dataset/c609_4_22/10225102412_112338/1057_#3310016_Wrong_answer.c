#include <stdio.h>

int calc(int n)
{
    int i,j,t,f,i1,j1;
    t=f=0;
    for (i=2;i<=n;i+=2){
        i1 = i/2;
        while (i==i1*2){
            i = i1;
            i1 = i1/2;
            t++;
        }
    }
    for (j=5;j<=n;j+=5){
        j1 = j/5;
        while (j==j1*5){
            j = j1;
            j1 = j1/5;
            f++;
        }
    }
    if (t>f) return f;
    else return t;
}

int main()
{
    int T,i,N;
    scanf("%d",&T);
    for (i=0;i<T;i++){
        scanf("%d",&N);
        printf("case #%d:\n%d",i,calc(N));
    }
    return 0;
}

