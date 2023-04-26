#include <stdio.h>
#include <stdlib.h>

int f(int n,int p,int m,int t){
    if(m==0) return p==t;
    if(p==1) return f(n,2,m-1,t);
    if(p==n) return f(n,n-1,m-1,t);
    return f(n,p-1,m-1,t)+f(n,p+1,m-1,t);
}

int main()
{
    int i,T;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        int n,p,m,t;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        printf("%d\n",f(n,p,m,t));
    }
    return 0;
}
