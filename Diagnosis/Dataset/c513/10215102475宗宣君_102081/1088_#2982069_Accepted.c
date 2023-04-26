#include <stdio.h>
long long int cmb(int a,int b)
{
    long long int res = 1,i,j,A[40];
    for(i = 0;i<b;i++)
        A[i] = i+1;
    for(i = 0;i<b;i++)
        {
            res = res * (a-i);
            for(j = 0;j<b;j++)
            {
                if(A[j]!=0&&res % A[j]==0) {res/=A[j];A[j] = 0;}
            }
        }
    return res;
}
int main()
{
    int T,i;
    long long res;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        int m,n;
        scanf("%d %d",&m,&n);
        printf("case #%d:\n",i);
        res = cmb(m,n);
        printf("%lld\n",res);

    }
    return 0;
}
