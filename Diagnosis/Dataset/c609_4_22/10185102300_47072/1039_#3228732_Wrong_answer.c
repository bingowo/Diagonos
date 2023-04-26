#include <stdio.h>
#include <string.h>

#define N 80

int maxDistance(char *s1,char *s2,char *s)
{  char *p1=strstr(s,s1),*p2=strstr(s,s2),*p; int t;
    if (p1==0||p2==0) return 0;
    while (p=strstr(p2+1,s2))  p2=p;
    return (t=p2-p1-strlen(s1))<0?0:t;
}



void solve()
{ char s1[N+1], s2[N+1], s[N+1],*p;
   scanf("%s",s1); scanf("%s",s2); scanf("%s",s);
   printf("%d\n",maxDistance(s1,s2,s));
}

int main()
{ int i,t;  scanf("%d\n",&t);
   for (i=0;i<t;i++) printf("case #%d:\n",i),solve();
   return 0;
}
