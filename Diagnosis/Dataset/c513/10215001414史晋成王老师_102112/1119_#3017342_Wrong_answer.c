#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{ int d,n,i,j,k[1100],s[1100];
double m,r,b[1100];
scanf("%d\n",&d);
scanf("%d\n",&n);
for(i=0;i<n;i++)
{scanf("%d %d\n",&k[i],&s[i]);
    
}
r=d;
for(i=0;i<n;i++)
{ b[i]=(d-k[i])/s[i];
  m=d/b[i];
  if(r>m) r=m;
}
printf("%.6lf",r);
}