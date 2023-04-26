#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n,j,a[50],k,co=0;
        scanf("%d",&n);
        for(j=0;j<32;j++)
        {
            a[j]=n%2;
            n=n>>1;
        }
        for(k=0;k<32;k++)
        {
            if(a[k]==a[k+1]) {co++;break;}
            else co++;
        }
        if(co>2) co--;
        printf("case #%d:\n%d",i,co);

    }
    return 0;
}
