#include<stdio.h>
#define N 1000
int gcd(int a,int b) { return b?gcd(b,a%b):a; }
int MIN(int*a,int n) { int r=a[0],i;for(i=1;i<n;i++) if (a[i]<r)r=a[i]; return r; }
int delta(int*a,int n,int lvl) { int r=0,i;for(i=0;i<n;i++) if (a[i]<lvl) r++; return r; }
int main()
{  int n,s,a[N],i,j,level,t,g;
   for (scanf("%d%d",&n,&s),i=0;i<n;i++) scanf("%d",a+i);
   for (level=MIN(a,n);s>=(t=delta(a,n,level+1)); s-=t,level++);
   if (level) printf("%d",level);
   if (s) g=gcd(t,s),printf("%s%d/%d",level==0?"":"+",s/g,t/g);
   printf("\n");
   return 0;
}