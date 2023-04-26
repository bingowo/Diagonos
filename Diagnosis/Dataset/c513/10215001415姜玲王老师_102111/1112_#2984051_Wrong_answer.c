#include <stdio.h>
#include <stdlib.h>

int main()
{
 int c[1001],i;
 for(i=1;i<1001;i++)
 {c[i]=(i/3)*((i-3)/2+(i%3)/2)/2+i/3;}
 int n;
 scanf("%d",&n);
 for(int i=0;i<n;i++)
 {
     int t,j,sum=0;
     scanf("%d",&t);
     if(t==0) printf("1\n");
     j=t-4;
     while(j>0)
     {sum=sum+c[j]+j/2+1;
         j-=4;
     }
     sum=sum+c[t]+t/2+1;
     printf("%d\n",sum);
 }

}
