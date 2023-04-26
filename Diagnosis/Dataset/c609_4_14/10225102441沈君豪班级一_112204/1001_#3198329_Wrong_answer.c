#include <stdio.h>
#include <stdlib.h>

void f(int a,int b)
{
    char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char x;
    if(a/b>0){
          f(a/b,b);
        }
    x = table[a%b];
    printf("%c",x);
}

int main()
{
    int M,N,T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d %d",&M,&N);
        if(M<0){
            M = -M;
            printf("-");}
        f(M,N);
        }

    return 0;
}
