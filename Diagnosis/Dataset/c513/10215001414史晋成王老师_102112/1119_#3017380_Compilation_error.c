#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{ double d,n,i,j,l1,l2; int k[1100],s[1100];
double m,r,b[1100];
scanf("%lf\n",&d);
scanf("%lf\n",&n);
for(i=0;i<n;i++)
{scanf("%d %d\n",&k[i],&s[i]);
    
}
r=d;
for(i=0;i<n;i++)
{ l1=k[i]; l2=s[i];
  b[i]=(d-l1)/l2;
  m=d/b[i];
  if(r>m) r=m;
}
printf("%.6lf",r);
}