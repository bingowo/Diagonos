#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int a[200][200];
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            scanf("%d",&a[i]);
    int count=0;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            int limit=n-1-i;
            int sum=a[i][j];
            if (limit>m-1-j) limit=m-1-j;
            for (int k=1; k<=limit; k++)
            {
                for (int l=0; l<=k; l++)sum+=a[i+l][j+k-l];
                if (sum>k)count++;
            }
            limit=n-1-i;
            sum=a[i][j];
            if (limit>j)limit=j;
            for (int k=1; k<=limit; k++)
            {
                for (int l=0; l<k; l++)sum+=a[i+l][j-k+l];
                if (sum>k)count++;
            }
            limit=i;
            sum=a[i][j];
            if(limit>m-1-j)limit=m-1-j;
            for (int k=1; k<=limit; k++)
            {
                for (int l=0; l<=k; l++)sum+=a[i-l][j+k-l];;
                if(sum>k)count++;
            }
            limit=i;
            sum=a[i][j];
            if (limit>j)limit=j;
            for(int k=1; k<=limit; k++)
            {
                for (int l=0; l<=k; l++)sum+=a[i-l][j-k+l];
                if(sum>k)count++;
            }
        }
    printf("%d\n",count);


    return 0;
}