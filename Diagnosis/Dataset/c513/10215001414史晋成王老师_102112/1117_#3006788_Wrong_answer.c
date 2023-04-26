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
{ long long int x0,y0,a[1000],b[1000],n,m,i,j,k,max,gbs,p0,p1;
  scanf("%lld %lld",&x0,&y0);
  scanf("%lld",&n);
  scanf("%lld %lld",&a[0],&b[0]);
  n=labs(a[0]-x0); m=labs(b[0]-y0);
   if(n>m) gbs=n; else gbs=m;
    p0=a[0];p1=b[0];
   for(i=1;i<n;i++)
  {scanf("%lld %lld",&a[i],&b[i]);
   n=labs(a[i]-x0); m=labs(b[i]-y0);
   if(n>m) max=n; else max=m;
   if(max<gbs||max==gbs) {gbs=max; p0=a[i];p1=b[i];} 
  }
  printf("%lld\n",gbs);
  printf("%lld %lld",p0,p1);
    
}