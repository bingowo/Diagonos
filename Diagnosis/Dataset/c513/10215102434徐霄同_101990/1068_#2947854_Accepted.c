#include <stdio.h>
int f(int n,int m)
{
    if(n<m)
        return 0;
    else if(n==m)
        return 1;
    else
        return 2*f(n-1,m)-f(n-1-m,m)+(1<<(n-1-m));
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    while(n!=-1&&m!=-1){
        printf("%d\n",f(n,m));
        scanf("%d%d",&n,&m);
    }
    return 0;
}
