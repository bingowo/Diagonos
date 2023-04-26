#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<math.h>
unsigned long long int bs (long long int x)
{ if(x>0) return x;
else return -x;
    
}
int main()
{ long long int x0,y0,x[1000],y[1000],n,m,i,j,k,max,gbs,p0,p1;
  scanf("%lld %lld",x0,y0);
  scanf("%lld",&n);
  for(i=0;i<n;i++)
  {scanf("%lld %lld",&a[i],&b[i]);
   n=labs(a[i]-x0); m=labs(b[i]-y0);
   if(n>m) max=n; else max=m;
   if(max<gbs) {gbs=max; p0=a[i];p1=b[i];} 
  }
  printf("%lld\n",gbs);
  printf("%lld %lld",p0,p1);
    
}