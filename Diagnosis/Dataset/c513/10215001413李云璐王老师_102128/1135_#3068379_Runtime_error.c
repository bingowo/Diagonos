#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

typedef struct {int str;int s[110];}F;

F sum(F a,F b)
{
    F c;
    int max=(a.str>b.str)?a.str:b.str;
    int yu=0;
    for(int i=0;i<max;i++)
      {c.s[i]=(a.s[i]+b.s[i]+yu)%10;
      yu=(a.s[i]+b.s[i]+yu)/10;}
    if(yu>0) {c.s[max]=yu%10;max++;}
    c.str=max;
    return c;
}

F hs(int n)
{
    F r[n];
    r[1].str=r[2].str=r[3].str=r[4].str=1;
    for(int i=0;i<110;i++)
      {r[1].s[i]=0;r[2].s[i]=0;r[3].s[i]=0;r[4].s[i]=0;}
    r[1].s[0]=1;
    r[2].s[0]=2;
    r[3].s[0]=3;
    r[4].s[0]=6;
    if(n>4)
    {
        for(int i=5;i<=n;i++)
        r[i]=sum(sum(hs(i-1),hs(i-2)),hs(i-4));
    }
    return r[n];
}



int main()
{
    int n;
    scanf("%d",&n);
    
    F w=hs(n);
    for(int h=w.str-1;h>=0;h--)
        printf("%d",w.s[h]);
   
    return 0;
}