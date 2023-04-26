#include <stdio.h>
#include <math.h>
char key[40]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

void f(int n,int r)
{
    if(n>0){
        f(n/r,r);
        printf("%c",key[n%r]);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,r;
        scanf("%d %d",&n,&r);
        if(n<0)printf("-");
        n=abs(n);
        f(n,r);
        printf("\n");
    }
    return 0;
}
