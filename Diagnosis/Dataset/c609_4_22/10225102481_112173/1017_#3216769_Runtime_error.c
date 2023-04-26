#include <stdio.h>
#include <stdlib.h>

sort(int a[],int t)
{
    int i=0,r;

    if(t=='A')
    {

        while(a[i]!=EOF){if(a[i]>a[i+1]){r=a[i];a[i]=a[i+1];a[i+1]=r;}i++;}

    }
    else
    {

        while(a[i]!=EOF){if(a[i]<a[i+1]){r=a[i];a[i]=a[i+1];a[i+1]=r;}i++;}

    }
}

int main()
{
     char t;
     int a[1000],i=0;
    scanf("%c\n",&t);
   while(scanf("%d",&a[i])!=EOF)i++;
   sort(a,t);
   printf("%d",a[0]);
   for(int j=0;j<=i;j++)
   {
       if(a[j]!=a[j+1])printf(" %d",a[j+1]);
   }


}
