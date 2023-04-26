#include<stdio.h>
#define N 120 
int ones(unsigned char d)
{  int r; for (r=0; d>0; d>>=1) if (d&1) r++; return r; }
int GCD(int a,int b)
{  return a%b?GCD(b,a%b):b; }
void solve()
{ char s[N+2]; int i,cnt1,cnt10,gcd; 

  fgets(s,N+2,stdin);
  
  
  for (cnt10=cnt1=i=0;s[i]!='\n';i++) cnt1+=ones(s[i]),cnt10+=8;
  gcd=GCD(cnt1,cnt10);
  printf("%d/%d\n",cnt1/gcd,cnt10/gcd);
}

int main()
{  int i,t;
   scanf("%d\n",&t);
   for (i=0;i<t;i++) /*printf("case #%d:\n",i),*/solve();
   return 0;
}