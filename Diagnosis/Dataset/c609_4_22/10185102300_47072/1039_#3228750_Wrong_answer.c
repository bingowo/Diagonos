#include <stdio.h>
#include <string.h>

#define N 80

int maxDistance(char *s1,char *s2,char *s)
{  char *p1=strstr(s,s1),*p2=strstr(s,s2),*p,*p1R,*p2R; int t1,t2;
    if (p1==0||p2==0||p1==p2) return 0;
    p1R=p1;  while (p=strstr(p1R+1,s1))  p1R=p;
    p2R=p2;  while (p=strstr(p2R+1,s2))  p2R=p;
    return (t1=abs(p2R-p1))>(t2=abs(p1R-p2))? t1:t2;
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