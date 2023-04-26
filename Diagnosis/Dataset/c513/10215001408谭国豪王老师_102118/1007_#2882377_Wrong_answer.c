#include <stdio.h>
#include <stdlib.h>

int main()

{  int n,a[20],i;
   int count(int x);
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
   for(i=0;i<n;i++)
   {
       printf("case #%d:\n%d\n",i,count(a[i]));
   }
   return 0;
}
int count(int x)
{
    int b[100],begin;
    int shu,t,j=0,max=0;
    while(x>0)
    {
       b[j]=x%2;
       x=x/2;
       j++;
    }
   for(t=1;t<j;t++)
    {begin=b[0];
     if(b[t]!=begin){shu++;
     if(shu>max);max=shu;}
     else{ begin=b[t];shu=0;}

    }
   return max;
}