#include <stdio.h>
#include <stdlib.h>


int main()
{
     char t;
     int a[101],i=0;
     scanf("%c\n",&t);
     while(scanf("%d ",&a[i])!=EOF)i++;

    int m=0,r,k;

    if(t=='A')
    {while(m<i){for(k=0;k<i-1-m;k++)if(a[k]>a[k+1]){r=a[k];a[k]=a[k+1];a[k+1]=r;}}}
    if(t=='D')
    {while(m<i){for(k=0;k<i-1-m;k++)if(a[k]<a[k+1]){r=a[k];a[k]=a[k+1];a[k+1]=r;}}}
     printf("%d",a[0]);
     for(int j=0;j<=i;j++)if(a[j]!=a[j+1])printf(" %d",a[j+1]);

    return 0;

}
