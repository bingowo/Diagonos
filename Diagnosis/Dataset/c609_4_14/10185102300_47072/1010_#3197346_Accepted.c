#include <stdio.h>

char digit(int d)
{ return d<10 ?  d+'0': d-10+'A'; }

void process(int n, int R)
{ if  (n)
   { int a=n/R,b; if ((b=n%R)<0) a++,b-=R; process(a,R),printf("%c",digit(b)); }
}
int main()
{ int n; int R;
   scanf("%d%d",&n,&R);
   if (n==0) printf("0"); else process(n,R);printf("\n");
   return 0;
}
