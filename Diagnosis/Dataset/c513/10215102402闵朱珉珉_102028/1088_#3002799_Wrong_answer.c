#include <stdio.h>
#include <stdlib.h>
int main()
{
    int T;
    scanf("%d",&T);
    long long C[42][42];
    C[0][0]=0;C[0][1]=0;
    C[1][0]=1;C[1][1]=1;
    for (int m=2;m<=40;m++)
    {
        C[m][0]=1;
        for (int n=1;n<=m;n++)
        {
            C[m][n]=C[m-1][n-1]+C[m-1][n];
        }
    }
    for (int i=0;i<T;i++)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        printf ("case #%d:\n%lld\n",i,C[m][n]);
    }
    return 0;
}
