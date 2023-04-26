#include <stdio.h>

int GCD(int a,int b){  return a%b?GCD(b,a%b):b; }

int main()
{ char s[31],s1[31]="",s2[31]="",*p=s,*q=s1,*p2; int r,m1,m2,gcd;
   scanf("%s",s);
   while (*p) { if (*p=='.') *q=0,q=s2,p++; *q++=*p++; } *q=0;

   for (p=s1,r=0;*p;p++) r=r*3+(*p=='2'? -1:(*p=='0'?0:1));

printf("%d\n",r);

   if (*s2)
   { for (p=s2,m2=1,m1=0;*p;p++) m2*=3, m1=m1*3+(*p=='2'? -1:(*p=='0'?0:1));
      if (r>0&&m1<0) r--,m1+=m2;
      else if (r<0&&m1>0) r++,m1-=m2;
       if (r==0)printf("-"),m1*=-1;
        if (r<0&&m1<0) m1*=-1;
       gcd=GCD(m1,m2);
     if (r)
      printf("%d %d %d\n",r,m1/gcd,m2/gcd);
      else printf("%d %d\n",m1/gcd,m2/gcd);
   }
   else printf("%d\n",r);

   return 0;
}


