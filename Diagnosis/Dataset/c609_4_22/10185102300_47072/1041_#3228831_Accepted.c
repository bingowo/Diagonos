#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 16

void f(char *s, char *t, int pos)
{ int i;
  for (i=pos;i<strlen(s);i++)
  {  char tt[N+1];
     f(s,(printf("%s\n",(sprintf(tt,"%s%c",t,s[i]),tt)),tt),i+1);
  }
}

int cmp(const void*a,const void*b){ return *(char*)a-*(char*)b; }

void solve()
{ char c, t[N+2],*pt=t,s[N+1]=""; int i=0;
  fgets(t,sizeof t,stdin);
  if (t[strlen(t)-1]=='\n') t[strlen(t)-1]=0;
  qsort(t,strlen(t),sizeof(*t),cmp);
  s[i++]=*pt++;
  while (c=*pt++) if (s[i-1]!=c) s[i++]=c;
  f(s,"",0);
}

#include <stdio.h>

int main()
{  int i,t;
   scanf("%d\n",&t);
   for (i=0;i<t;i++)
   { printf("case #%d:\n",i);
      solve();
   }
   return 0;
}