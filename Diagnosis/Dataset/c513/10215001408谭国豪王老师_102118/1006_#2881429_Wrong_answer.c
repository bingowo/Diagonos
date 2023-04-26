#include <stdio.h>
#include <stdlib.h>

int main()
{   int n,i,j,d, a[10];
    char c[10][20];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",c[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;c[i][j];j++)
           {

            if(c[i][j]='1')d=1;
            else if(c[i][j]='0')d=0;
            else d=-1;
            a[i]=a[i]*3+d;}
    }
    for(i=0;i<n;i++)
    {
        printf("case #0;\n%d",a[i]);
        printf("\n");
    }
    return 0;
}