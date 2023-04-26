#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{ int T,i,j;
  scanf("%d",&T);
  for(i=0;i<=T-1;i++)
   { char a[51]={0};
     long double r;
     scanf("%s",a);
     int length=strlen(a);
     for(j=2;j<length;j++) r+=a[j]*pow(8,-(j-1));
     printf("case #%d:\n",i);
     printf("%lf\n",r);
   }
   return 0;
}

