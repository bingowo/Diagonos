#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int a[10][1801]={0};
    int b[10],c[901]={0};
    int k,j,i;
    scanf("%d",&n);
    int sum=0;
    for( i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        sum+=b[i];
    }
    for( i=0;i<n;i++)
    {
        a[i][900+b[i]]=1;
        a[i][900-b[i]]=1;
        for(j=0;j<i;j++)
        for(k=b[i];k<1801;k++)
        {
            if(a[j][k]){a[i][k+b[i]]=1;
                        a[i][k+b[i]]=1;}

        }
    }

    for(i=1;i<=sum;i++)
    {
        for(j=0;j<10;j++)
        {
            if(a[j][i+900]) c[i]=1;
        }
    }
    for(i=1;i<=sum;i++)
    {
        printf("%d",c[i]);
    }

}
