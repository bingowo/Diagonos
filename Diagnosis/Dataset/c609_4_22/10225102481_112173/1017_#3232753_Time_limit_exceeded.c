#include <stdio.h>
#include <stdlib.h>


int main()
{
     char t;
     int a[101],i=0;
     scanf("%c\n",&t);
     while(scanf("%d ",&a[i])!='\n')i++;

    int k=0,r;

    if(t=='A')
    {while(k<i){if(a[k]>a[k+1]){r=a[k];a[k]=a[k+1];a[k+1]=r;}k++;}}
    else
    {while(k<i){if(a[k]<a[k+1]){r=a[k];a[k]=a[k+1];a[k+1]=r;}k++;}}
     printf("%d",a[0]);
     for(int j=0;j<=i;j++)
    {
        if(a[j]!=a[j+1])printf(" %d",a[j+1]);
    }


}
