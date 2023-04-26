#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n,a[32],p=1,q=1;
        for(int j=0;j<31;j++)a[j]=0;
        scanf("%d",&n);
        int m=0;
        while (n>0)
        {
            a[m++]=n&1;
            n=n>>1;
        }
        a[m]='\n';
        for(int j=0;j<m-1;j++)
        {
            if(a[j]!=a[j+1])
                p++;
            if (p>=q)q=p;
            if (a[j]==a[j+1])p=1;
        }
        printf("case #%d:\n",i);
        printf("%d\n",q);
    }
}
