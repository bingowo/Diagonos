#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void base(int a[][1000])
{
    int i,j,flag;
    a[0][0]=1;
    for(i=0;i<=30;i++)
    {
        flag=0;
        for(j=0;j<1000;j++)
        {
            if(i==0&&j!=0) a[i][j]=0;
            else if(i>0)
            {
                a[i][j]=2*a[i-1][j]+flag;
                flag=a[i][j]/10;
                a[i][j]=a[i][j]%10;
            }
        }
    }
}

int main()
{
    int N,i,j;
    int A[31][1000];
    base(A);
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        int t,k;
        scanf("%d",&t);
        for(j=999;j>=0;j--)
        {
            if(A[t][j]!=0) break;
        }
        k=j;
        printf("case #%d:\n",i);
        for(j=k;j>=1;j--)
            printf("%d",A[t][j]);
        printf("%d\n",A[t][0]);
    }
    return 0;
}
