#include<stdio.h>
int main()
{
    int T;
    scanf("%d\n",&T);
    int t=0;
    for(t=0;t<T;t++)
    {
        long long int C[41][41];
        C[0][0]=0;
        int m,n;
        scanf("%d %d",&m,&n);
        int p,q;
        for(p=1;p<=m;p++)
        {
            C[p][0]=1;
            C[p][1]=p;
        }
        for(p=1;p<=m;p++)
        {
            C[p][p]=1;
        }
        for(p=2;p<=m;p++)
        {
            for(q=1;q<p;q++)
            {
                C[p][q]=C[p-1][q-1]+C[p-1][q];
            }
        }    
        printf("case #%d:\n",t);
        printf("%lld\n",C[m][n]);
    }
    return 0;
}