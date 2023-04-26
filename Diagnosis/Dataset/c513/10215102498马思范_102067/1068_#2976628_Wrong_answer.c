#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int result(int n,int m)
{
    if(n<m)
        return 0;
    if(n==m)
        return 1;
    return 2* result(n-1,m)- result(n-m-1,m)+ pow(2,n-m-1);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    while (m!=-1&&n!=-1)
    {
        int r= result(n,m);
        printf("%d\n",r);
        scanf("%d%d",&m,&n);
    }
    return 0;
}