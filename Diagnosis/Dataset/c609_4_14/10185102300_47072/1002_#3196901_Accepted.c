#include <stdio.h>

int main()
{   int i,T;
     for(scanf("%d",&T),i=0;i<T;i++)
     {    int bits,k,n,a[32],r,maxR=0;
           printf("case #%d:\n",i);
           scanf("%d",&n);
           for  (bits=0;n!=0;bits++,n>>=1)  a[bits]=n%2;
           for (k=0;k<bits;k++)
           {  for (r=1;k+r<bits&& a[k+r-1]!=a[k+r];r++);
               if (r>maxR) maxR=r;
           }
           printf("%d\n", maxR);
     }

    return 0;
}