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
{ long long int x0,y0,a[1100000]={0},N,b[1100000]={0},i,j,k,p0,p1;
  unsigned long long int max,gbs,n,m;
  scanf("%lld %lld",&x0,&y0);
  scanf("%lld",&N);
  scanf("%lld %lld",&a[0],&b[0]);
  n=bs(a[0]-x0); m=bs(b[0]-y0);
   if(n>m) gbs=n; else gbs=m;
    p0=a[0];p1=b[0];
   for(i=1;i<N;i++)
  {scanf("%lld %lld",&a[i],&b[i]);
   n=bs(a[i]-x0); m=bs(b[i]-y0);
   if(n>m) max=n; else max=m;
   if(max<gbs) {gbs=max; p0=a[i];p1=b[i];} 
   else if(max==gbs)
   { if(a[i]<p0) po=a[i];
       
   }
  }
  printf("%llu\n",gbs);
  printf("%lld %lld",p0,p1);
    
}