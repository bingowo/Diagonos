#include <stdio.h>
#include <math.h>

int main()
{   char a[10][52];
   
    int i,j,t,n,b[10];
     for(i=0;i<10;i++)
    {for(j=0;j<52;j++)a[i][j]='\0';}
    

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
            b[i]=b[i]+(a[i][t]-'0')*pow(8,t-1);
        }

    }
    for(i=0;i<n;i++)
    {
        printf("case #%d:\n%d\n",i,b[i]);
    }
    return 0;
}
