#include <stdio.h>
#include <math.h>

int main()
{   char a[10][52]={'\0'};
    int i,j,t,n,b[10];

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {b[i]=0;}
    for(i=0;i<n;i++)
    {
        scanf("%s",a[i]);
    }
    for(i=0;i<n;i++)
    {   j=0;
        while(a[i][j])
            j++;
        for(t=2;t<j;t++)
        {
            b[i]=b[i]+(a[i][t]-'0')/pow(8,1-t);
        }

    }
    for(i=0;i<n;i++)
    {
        printf("case #%d:\n%d\n",i,b[i]);
    }
    return 0;
}
