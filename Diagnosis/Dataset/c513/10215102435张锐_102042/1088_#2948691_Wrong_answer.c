#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        long long int sum=1;
        for(int j=m,k=0;k<n;k++,j--)
        {
            sum=sum*j;
        }
        for(int k=n;k>=1;k--) sum=sum/k;
        printf("case #%d:\n",i);
        if(m==n) printf("1\n");
        else printf("%lld\n",sum);
    }
    return 0;
}