#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

typedef struct {int str;int s[1100];}F;

F sum(F a,F b)
{
    F c;
    int max=(a.str>b.str)?a.str:b.str;
    int yu=0;
    for(int i=0;i<max;i++)
      {c.s[i]=(a.s[i]+b.s[i]+yu)%10;
      yu=(a.s[i]+b.s[i]+yu)/10;}
    while(yu>0) {c.s[max]=yu%10;yu/=10;max++;}
    c.str=max;
    return c;
}

F hs(int n)
{
    F q1,q2,q3,q4;
    q1.str=q2.str=q3.str=q4.str=1;
    for(int i=0;i<1100;i++)
      {q1.s[i]=0;q2.s[i]=0;q3.s[i]=0;q4.s[i]=0;}
    q1.s[0]=1;
    q2.s[0]=2;
    q3.s[0]=3;
    q4.s[0]=6;
    if(n==1) return q1;
    if(n==2) return q2;
    if(n==3) return q3;
    if(n==4) return q4;
    if(n>4)
    {
        F q;
        q=sum(sum(hs(n-1),hs(n-2)),hs(n-4));
        return q;
    }
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
