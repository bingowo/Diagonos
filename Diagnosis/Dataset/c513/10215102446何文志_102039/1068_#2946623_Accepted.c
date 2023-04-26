#include <stdio.h>
#include <stdlib.h>

int f(n,m){
    if(n<m){return 0;}
    if(n==m){return 1;}
    return 2*f(n-1,m)-f(n-m-1,m)+(1<<(n-m-1));
}

int main()
{
    int n = 0,m = 0;
    while(!((n==-1)&&(m==-1))){
        scanf("%d%d",&n,&m);
        if((n==-1)&&(m==-1)){break;}
        int res = f(n,m);
        printf("%d\n",res);
    }
    return 0;
}
