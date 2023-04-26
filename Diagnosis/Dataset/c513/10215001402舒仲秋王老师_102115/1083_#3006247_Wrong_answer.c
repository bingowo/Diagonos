#include <stdio.h>
#include <stdlib.h>

void base(int a[][250])
{
    int i,k,flag=0;
    a[1][0]=1;
    for(i=1;i<=1000;i++)
    {
        for(k=0;k<250;k++)
        {
            if(i==1&&k!=0) a[i][k]=0;
            else if(i>1)
            {
                int c=a[i-1][k]*i;
                a[i][k]=c%10+flag;
                flag=c/10;
            }
        }
    }
}

int main()
{
    int N,i;
    scanf("%d",&N);
    int A[1001][250];
    base(A);
    for(i=0;i<N;i++)
    {
        int a,j;
        scanf("%d",&a);
        for(j=0;;j++)
            if(A[a][j]!=0) break;
        printf("case #%d:\n",i);
        printf("%d\n",j);
    }
    return 0;
}
