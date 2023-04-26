#include <stdio.h>
#include <stdlib.h>
const char table[]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
void cc(int x,int y)
{
    int a,b;
        a=x/y;
        b=x%y;
        if (a>0)
            cc(a,y);
        printf("%c",table[b]);

}
int main()
{ int n,a,b,c,d;
  scanf("%d",&n);
  if (n>0)
  {
  while(scanf("%d%d",&a,&b)!=EOF)
  {
      if (a<0)
      {
          printf("-");
          a=-a;
      }
      cc(a,b);
      printf("\n");
  }
  }
    return 0;
}
