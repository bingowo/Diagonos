#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int Comb(int n,int m)
{
    if(n == m)
        return 1;
    else if(m == 1)
        return n % 1007;
    else if(m == 0)
        return 0;
    else
        return (Comb(n - 1,m) % 1007 + Comb(n - 1,m - 1) % 1007) % 1007;
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int a,b,k,n,m;
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        int i,j,ef;
        ef = (((int)pow(a,n) % 10007) * ((int)pow(b,m) % 10007)) % 10007;
        ef = (ef * Comb(n,m)) % 10007;
        printf("case #%d:\n%d\n",i,ef);
        return 0;
    }
}