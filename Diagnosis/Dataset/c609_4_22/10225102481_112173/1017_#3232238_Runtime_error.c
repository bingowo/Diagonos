#include <stdio.h>
#include <stdlib.h>


int main()
{
     char t;
     int a[1000],i=0;
     scanf("%c\n",&t);
     while(scanf("%d",&a[i])!=EOF)i++;

    int k=0,r;

    if(t=='A')
    {while(a[k]!=EOF){if(a[k]>a[k+1]){r=a[k];a[k]=a[k+1];a[k+1]=r;}k++;}}
    else
    {while(a[k]!=EOF){if(a[k]<a[k+1]){r=a[k];a[k]=a[k+1];a[k+1]=r;}k++;}}
     printf("%d",a[0]);
     for(int j=0;j<=i;j++)
    {
        if(a[j]!=a[j+1])printf(" %d",a[j+1]);
    }


}
