#include <stdio.h>
#include <stdlib.h>

struct shh
{
    int sa;
    int sb;
};
int main()
{
    int a,n,m,x,i,b;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    struct shh sh[n];
    sh[1].sa=1,sh[1].sb=0;
    sh[2].sa=0,sh[2].sb=1;
    for(i=3;i<n;i++)
    {
        sh[i].sa=sh[i-1].sa+sh[i-2].sa;
        sh[i].sb=sh[i-1].sb+sh[i-2].sb;
    }
    b=(m-a-sh[n-1].sa*a)/(sh[n-1].sb-1);
    printf("%d\n",sh[x].sa*a+sh[x].sb*b+a-b);
    return 0;
}
