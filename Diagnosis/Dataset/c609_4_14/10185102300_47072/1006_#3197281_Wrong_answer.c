#include<stdio.h>

void solve()
{ int a[128],digit=0,ai=1,i; char s[61],*p=s; 
  long long ans=0;
  for (i=0;i<128;i++) a[i]=-1;
  scanf("%s",s); a[*p]=1;
  while (*++p)
    if (a[*p]==-1) a[*p]=digit,digit=digit?digit+1:2,ai++;
  if (ai<2) ai=2;
  p=s; while (*p) ans=a[*p++]+ans*ai;
  printf("%lldd\n",ans);
}

int main()
{  int i,t; 
   scanf("%d\n",&t);
   for (i=0;i<t;i++) printf("case #%d:\n",i),solve();
   return 0;
}
