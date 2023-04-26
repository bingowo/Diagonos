#include <stdio.h>
#include <stdlib.h>

void base(int a[][251])
{
    int i,k,flag;
    a[1][0]=1;
    for(i=1;i<=1000;i++)
    {
        flag=0;
        for(k=0;k<251;k++)
        {
            if(i==1&&k!=0) a[i][k]=0;
            else if(i>1)
            {
                a[i][k]=(a[i-1][k]*i+flag)%10;
                flag=(a[i-1][k]*i+flag)/10;
            }
        }
    }
}

int main()
{
    int N,i;
    scanf("%d",&N);
    int A[1001][251];
    base(A);
    for(i=0;i<N;i++)
    {
        int a,j;
        scanf("%d",&a);
        for(j=0;j<250;j++)
           if(A[a][j]!=0) break;
        printf("case #%d:\n",i);
        printf("%d\n",j);
    }
    return 0;
}
