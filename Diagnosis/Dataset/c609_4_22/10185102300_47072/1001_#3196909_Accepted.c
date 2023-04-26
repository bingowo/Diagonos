#include <stdio.h>

char digit(int d)
{ return d<10 ?  d+'0': d-10+'A'; }

void process(int n, int R)
{ if  (n>0) process(n/R,R),printf("%c",digit(n%R)); }

int main()
{   int i,T;
     for(scanf("%d",&T),i=0;i<T;i++)
     {    int n,R;
//           printf("case #%d:\n",i);
           scanf("%d%d",&n,&R);
           if (n<0) printf("-"),n=-n;
           if (n==0) printf("0"); else process(n,R);
           printf("\n");
     }

    return 0;
}