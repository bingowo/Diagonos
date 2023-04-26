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
        unsigned long long sum=1;
        int j,k;
        for(int j=m,k=0;k<10&&k<n;k++,j--)
        {
            sum=sum*j;
        }
        for(int kk=n;kk>=1;kk--) sum=sum/kk;
        for(;k<n;k++,j--) sum=sum*j;
        printf("case #%d:\n",i);
        if(m==n||n==0) printf("1\n");
        else printf("%llu\n",sum);
    }
    return 0;
}
