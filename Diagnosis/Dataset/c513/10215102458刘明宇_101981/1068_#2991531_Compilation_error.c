#include <stdio.h>
#include <stdlib.h>


int f(int n,int m)
{
    if(n<m) return 0;
    if(n == m) return 1;
    return 2*f(n-1,m)-f(n-m-1,m) + (1<<(n-m-1));
}

int main()
{
    int n,m;
    while(n!=-1 &&m!=-1){
        scanf("%d %d",&n,&m);
        int res = f(n,m);
        printf("%d\n",res);
    }
    print("1");
}
