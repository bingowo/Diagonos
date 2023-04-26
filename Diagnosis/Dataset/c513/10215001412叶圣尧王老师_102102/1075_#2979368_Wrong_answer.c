#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int m,n,sum,k=0;char s[401];
    scanf("%d %d",&m,&n);
    int A[m][n],i,j;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)scanf("%d",&A[i][j]);
    i=0;j=0;sum=A[0][0];
    while(i!=m-1&&j!=n-1)
    {
        if(i==m-1)
        {s[k++]='R';j++;sum+=A[i][j];}
        if(j==n-1)
        {s[k++]='D';i++;sum+=A[i][j];}
        else
        {
            if(A[i][j+1]<A[i+1][j]){s[k++]='R';j++;sum+=A[i][j];}
            else if(A[i][j+1]>A[i+1][j]){s[k++]='D';i++;sum+=A[i][j];}
        }
    }
    printf("%d\n%s",sum,s);
}