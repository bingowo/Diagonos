#include<stdio.h>

void f()
{ int first=1,i,e;
  for (i=8;i>=0;i--)
  {  scanf("%d",&e);
     if (!first&&e>0) printf("+");
     if (i==0) { if (first||e) printf("%d",e); }
     else if (e)
     { if (e==-1)  printf("-");  else if (e!=1) printf("%d",e);
       printf("x");
       if (i!=1) printf("^%d",i);
       first=0;
     }
  }
  printf("\n");
}

int main()
{ int I,T,n;
  for(scanf("%d\n",&T),I=0;I<T;I++)
      printf("case #%d:\n",I),f();
  return 0;
}